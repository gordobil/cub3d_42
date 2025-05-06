/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:18:42 by ngordobi          #+#    #+#             */
/*   Updated: 2025/05/06 12:57:23 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	init_cub3d(t_cub3d *cub3d)
{
	cub3d->map_path = NULL;
	cub3d->map_fd = 0;
	cub3d->map = NULL;
	cub3d->elements = malloc(7 * sizeof(char *));
	if (!cub3d->elements)
		return (free_cub3d(cub3d), -ERROR_FATAL);
	cub3d->start_pos = 'X';
	cub3d->start_y = -1;
	cub3d->start_x = -1;
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub3d	cub3d;
	int		ret;

	if (init_cub3d(&cub3d) < 0)
		return (free_cub3d(&cub3d), error(ERROR_FATAL));
	if (argc != 2 || !argv[1] || get_path(argv[1], &cub3d) != 0)
		return (free_cub3d(&cub3d), error(ERROR_ARGS));
	ret = check_file(&cub3d);
	if (ret < 0)
		return (free_cub3d(&cub3d), error(-ret));
/* 	if (mlx_management(cub3d) < 0)
		return (free_cub3d(&cub3d), error(ERROR_MLX)); */
	return (free_cub3d(&cub3d));
}
