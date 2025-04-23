/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:23:09 by ngordobi          #+#    #+#             */
/*   Updated: 2025/04/16 12:23:09 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_path(char *path, t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (path[i + 1] != '\0')
		i++;
	if (path[i - 3] != '.' || path[i - 2] != 'c' || path[i - 1] != 'u'
		|| path[i] != 'b')
		return (-2);
	cub3d->map_fd = open(path, O_RDONLY);
	if (cub3d->map_fd < 0)
		return (close(cub3d->map_fd), -2);
	cub3d->map_path = ft_strdup(path);
	return (0);
}

int	elem_manag(char **elem, int flag)
{
	int	i;

	if (flag == 1)
	{
		elem[0] = ft_strdup("NO");
		elem[1] = ft_strdup("SO");
		elem[2] = ft_strdup("WE");
		elem[3] = ft_strdup("EA");
		elem[4] = ft_strdup("F");
		elem[5] = ft_strdup("C");
		elem[6] = NULL;
	}
	else if (flag == -1)
	{
		i = -1;
		while (elem[++i] != NULL && i < 7)
			free (elem[i]);
		elem = NULL;
	}
	return (0);
}

int	index_update(int i, int j, char *line)
{
	if (j >= 0 && j < 4)
		i += 2;
	else if (j >= 4 && j <= 5)
		i += 1;
	i = jump_empty(line, i);
	return (i);
}

int	get_elements(char *line, t_cub3d *cub3d)
{
	char		*elem[7];
	int			i;
	static int	j;

	if (j > 5)
		return (j++, 1);
	elem_manag(elem, 1);
	i = jump_empty(line, 0);
	if (i == -1)
		return (elem_manag(elem, -1), 0);
	if ((j >= 0 && j <= 3 && elem[j][0] == line[i] && elem[j][1] == line[i + 1]
		&& (line[i + 2] == ' ' || line[i + 2] == '\t')) || (j >= 4 && j <= 5
		&& elem[j][0] == line[i] && (line[i +1] == ' ' || line[i +1] == '\t')))
	{
		i = index_update(i, j, line);
		if (line[i] == '\0' || line[i] == '\n' || line[i] == '\r')
			return (elem_manag(elem, -1), -2);
		cub3d->elements[j] = ft_substr(line, i, get_elem_length(i, line));
	}
	else
		return (elem_manag(elem, -1), -2);
	// if (j == 5)
	// 	return (j++, elem_manag(elem, -1), 1);
	return (j++, elem_manag(elem, -1), 0);
}

int	check_file(t_cub3d *cub3d)
{
	char	*line;
	int		ret;

	while (1)
	{
		ft_printf("------------------------------------------\n\n");
		line = get_next_line(cub3d->map_fd);
		if (line == NULL)
			break ;
		ft_printf("line: %s\n", line);
		if (jump_empty(line, 0) >= 0)
		{
			ret = get_elements(line, cub3d);
			ft_printf("get_elements: %d\n", ret);
			if (ret == -1)
				return (close(cub3d->map_fd), -3);
			else if (ret == 1)
				ret = get_map(cub3d, line);
			ft_printf("ret:%d\n", ret);
			if (ret != 0)
				break ;
		}
		ft_printf("free line\n");
		if (line)
			free(line);
		ft_printf("freed\n");
		line = NULL;
		ft_printf("NULL\n\n");
	}
	if (ret < 0)
		return (close(cub3d->map_fd), ret);
	return (close(cub3d->map_fd), check_map(cub3d));
}
