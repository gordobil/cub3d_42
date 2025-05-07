/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 11:32:29 by ngordobi          #+#    #+#             */
/*   Updated: 2025/05/06 11:32:29 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	close_window(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->window);
	mlx_destroy_display(cub3d->mlx);
	return (exit(0), 0);
}

int	handle_input(int keysym, t_cub3d *cub3d)
{
	if (keysym == Q || keysym == ESC)
		close_window(cub3d);
	return (0);
}

int	no_event(void)
{
	return (0);
}

int	mlx_management(t_cub3d cub3d)
{
	cub3d.mlx = mlx_init();
	if (!cub3d.mlx)
		return (free(cub3d.mlx), free_cub3d(&cub3d), -ERROR_MLX);
	cub3d.window = mlx_new_window(cub3d.mlx, 1080, 720, "cub3d");
	if (!cub3d.window)
		return (free(cub3d.mlx), free(cub3d.window),
			free_cub3d(&cub3d), -ERROR_MLX);
	mlx_key_hook(cub3d.window, &handle_input, &cub3d);
	mlx_loop_hook(cub3d.mlx, &no_event, &cub3d);
	mlx_hook(cub3d.window, 17, 1, close_window, &cub3d);
	mlx_loop(cub3d.mlx);
	return (free(cub3d.mlx), free(cub3d.window), 0);
}
