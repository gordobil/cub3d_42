/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:15:33 by ngordobi          #+#    #+#             */
/*   Updated: 2025/04/29 14:09:48 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	dup_map_spaced(t_cub3d *cub3d, int i, int j)
{
	char	**spaced;
	int		x = 0;
	int		y = 0;

	x++;
	y++;
	spaced = malloc((i + 3) * sizeof(char *));
	i += 2;
	spaced[i] = NULL;
	while (--i >= 0)
		spaced[i] = malloc((j + 3) * sizeof(char));
	return (ft_printf("%m", cub3d->map), free_matrix(spaced), 0);
}

int	map_check(t_cub3d *cub3d)
{
	int		i;
	int		j;
	
	i = 0;
	while (cub3d->map[i] != NULL)
	{
		j = 0;
		while (cub3d->map[i][j] != '\0')
		{
			if (cub3d->map[i][j] != '1' && cub3d->map[i][j] != '0'
				&& cub3d->map[i][j] != ' ')
			{
				if ((cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S'
					|| cub3d->map[i][j] == 'E' || cub3d->map[i][j] == 'W')
					&& cub3d->start_pos == 'X')
					cub3d->start_pos = cub3d->map[i][j];
				else
					return(-ERROR_MAP);
			}
			j++;
		}
		i++;
	}
	return (dup_map_spaced(cub3d, i, j));
}
