/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:15:33 by ngordobi          #+#    #+#             */
/*   Updated: 2025/05/01 13:58:36 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	dup_map_spaced(t_cub3d *cub3d, int i, int j)
{
	char	**spaced;
	int		x;
	int		y;
	int		z;

	ft_printf("%m\n\ni:%d - j:%d\n\n", cub3d->map, i, j);
	spaced = malloc((i + 3) * sizeof(char *));
	spaced[i + 2] = NULL;
	y = -1;
	while (++y < i + 2)
		spaced[y] = malloc((j + 3) * sizeof(char));
	y = -1;
	while (++y < i + 2)
	{
		ft_printf("---%d---\n", y);
		x = -1;
		if (y == 0 || y == i + 1){
			while (++x < j + 2)
				spaced[y][x] = ' ';
			ft_printf("0/end\n");}
		else
		{
			z = 0;
			while (++x < (j + 2))
			{
				if (cub3d->map[y + 1][z] != '\0' && x > 0 && x < (j + 1))
				{
					spaced[y][x] = cub3d->map[y - 1][z];
					ft_printf("[%d][%d]%c|%c|\n", y, x, spaced[y][x], cub3d->map[y - 1][z]);
					z++;
				}
				else{
					spaced[y][x] = ' ';
					ft_printf("[%d][%d]%c|\n", y, x, spaced[y][x]);
				}
			}
		}
		ft_printf("%s|\n", spaced[y]);
		spaced[y][x] = '\0';
	}
	return (ft_printf("%m", spaced), free_matrix(spaced), 0);
}

int	map_check(t_cub3d *cub3d)
{
	int		i;
	int		j;
	int		max_j;
	
	max_j = 0;
	i = -1;
	while (cub3d->map[++i] != NULL)
	{
		j = -1;
		while (cub3d->map[i][++j] != '\0')
		{
			if ((cub3d->map[i][j] != '1' && cub3d->map[i][j] != '0'
				&& cub3d->map[i][j] != ' ') && (cub3d->start_pos == 'X' &&
					(cub3d->map[i][j] == 'N' || cub3d->map[i][j] == 'S'
					|| cub3d->map[i][j] == 'E' || cub3d->map[i][j] == 'W')))
			{
				cub3d->start_pos = cub3d->map[i][j];
				cub3d->start_y = i;
				cub3d->start_x = j;
			}
			else if (cub3d->map[i][j] != '1' && cub3d->map[i][j] != '0'
				&& cub3d->map[i][j] != ' ')
				return(-ERROR_MAP);
			if (j > max_j)
				max_j = j;
		}
	}
	i = flood_fill(cub3d->start_y, cub3d->start_x, cub3d->map, cub3d->start_pos);
	ft_printf("%m\n%d\n", cub3d->map, i);
	return (0);
	//return (dup_map_spaced(cub3d, i, max_j + 1));
}
