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
		return (-1);
	cub3d->map_fd = open(path, O_RDONLY);
	if (cub3d->map_fd < 0)
		return (close(cub3d->map_fd), -1);
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

int	check_elem(char *line, t_cub3d *cub3d)
{
	char		*elem[7];
	int			i;
	static int	j;

	if (j > 5)
		return (1);
	i = 0;
	elem_manag(elem, 1);
	while (line[i] != '\0' && line[i] != '\n'
		&& (line[i] == ' ' || line[i] == '	'))
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (elem_manag(elem, -1), 0);
	if ((j >= 0 && j <= 3 && elem[j][0] == line[i] && elem[j][1] == line[i + 1]
		&& (line[i + 2] == ' ' || line[i + 2] == '	'))
		|| ((j == 4 || j == 5) && elem[j][0] == line[i]
		&& (line[i + 1] == ' ' || line[i + 21] == '	')))
	{
		if (j >= 0 && j < 4)
			i += 2;
		else if (j >= 4 && j <= 5)
			i += 1;
		while (line[i] != '\0' && line[i] != '\n'
			&& (line[i] == ' ' || line[i] == '	'))
			i++;
		if (line[i] == '\0' || line[i] == '\n')
			return (elem_manag(elem, -1), -1);
		cub3d->elements[j] = ft_substr(line, i, ft_strlen(line) - i - 1);
	}
	if (j == 5)
		return (j++, elem_manag(elem, -1), 1);
	return (j++, elem_manag(elem, -1), 0);
}

int	empty_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\r' && line[i] != '\n' &&
		(line[i] == ' ' || line[i] == '	'))
		i++;
	if (line[i] == '\0' || line[i] == '\r' || line[i] == '\n')
		return (1);
	return (0);
}

int	check_file(t_cub3d *cub3d)
{
	char	*line;
	int		ret;

	while (1)
	{
		line = get_next_line(cub3d->map_fd);
		if (line == NULL && cub3d->map_fd > 0)
			break ;
		if (empty_line(line) == 0)
		{
			ret = check_elem(line, cub3d);
			if (ret != 0)
				return (ret);
		}
		if (line)
			free(line);
		line = NULL;
	}
	return (0);
}
