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

int	check_file(t_cub3d *cub3d)
{
	char	*line;
	int		i;

	i = 1;
	while (cub3d->map_fd)
	{
		line = get_next_line(cub3d->map_fd);
		if (line == NULL)
			break ;
		ft_printf("[%d] %s\n", i, line);
		free(line);
		line = NULL;
		i++;
	}
	return (0);
}
