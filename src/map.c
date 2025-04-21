/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:15:33 by ngordobi          #+#    #+#             */
/*   Updated: 2025/04/21 14:41:48 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_new_map(t_cub3d *cub3d, char **new_map, char *line)
{
	int i;

	i = 0;
	while (cub3d->map[i] != NULL)
	{
		new_map[i] = cub3d->map[i];
		i++;
	}
	new_map[i] = ft_strdup(line);
	if (!new_map || !new_map[i])
		return (free_matrix(new_map), -3);
	new_map[i + 1] = NULL;
	return (0);
}

int	get_map(t_cub3d *cub3d, char *line)
{
	static int	i;
	char		**new_map;

	if (!cub3d->map || !cub3d->map[0])
	{
		cub3d->map = malloc(2 * sizeof(char *));
		if (!cub3d->map)
			return (-3);
		cub3d->map[0] = ft_strdup(line);
		if (!cub3d->map[0])
			return (-3);
		cub3d->map[1] = NULL;
		i = 1;
		return (0);
	}
	new_map = malloc((i + 1) * (sizeof(char *)));
	if (!new_map)
		return (-3);
	if (get_new_map(cub3d, new_map, line) != 0)
		return (-3);
	free(cub3d->map);
	cub3d->map = new_map;
	return (i++, free_matrix(new_map), 0);
}

int	check_map(t_cub3d *cub3d)
{
	ft_printf("%s\n", cub3d->map_path);
	return (-3);
}
