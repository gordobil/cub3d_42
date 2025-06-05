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

int get_matrix_height(char **matrix)
{
    int i = 0;
    while (matrix[i])
        i++;
    return i;
}

int is_walkable(t_cub3d *cub3d, int new_x, int new_y)
{
    int map_x = new_x / SQ;
    int map_y = new_y / SQ;

    if (map_y < 0 || map_y >= get_matrix_height(cub3d->map) ||
        map_x < 0 || map_x >= (int)ft_strlen(cub3d->map[map_y]))
        return (0); // fuera del mapa

    if (cub3d->map[map_y][map_x] == '1')
        return (0);

    return (1);
}

int render_frame(t_cub3d *cub3d)
{
	ft_printf("x:%d y:%d\n", cub3d->player->x, cub3d->player->y);
	draw_minimap(cub3d);
	return (0);
}

int	handle_input(int keysym, t_cub3d *cub3d)
{
	int new_x;
	int new_y;
	int	old_x;
	int	old_y;
	int	old_ang;

	new_x = 0;
	new_y = 0;
	old_x = cub3d->player->x;
	old_y = cub3d->player->y;
	old_ang = cub3d->player->ang;
	if (keysym == Q || keysym == ESC)
		close_window(cub3d);
	if (keysym == D || keysym == RIGHT)
	{
		if (cub3d->player->ang == 359)
			cub3d->player->ang = 0;
		else
			cub3d->player->ang += 1;
	}
	else if (keysym == A || keysym == LEFT)
	{
		if (cub3d->player->ang == 0)
			cub3d->player->ang = 359;
		else
			cub3d->player->ang -= 1;
	}
	if (keysym == W || keysym == UP)
	{
		new_x = cub3d->player->x + cos(DEG_TO_RAD(cub3d->player->ang)) * cub3d->player->speed;
		new_y = cub3d->player->y + sin(DEG_TO_RAD(cub3d->player->ang)) * cub3d->player->speed;
		if (is_walkable(cub3d, new_x, new_y))
		{
			printf("Entro %d\n", new_y);
			cub3d->player->x = new_x;
			cub3d->player->y = new_y;
		}
		else
			printf("No ntro\n");
	}
	else if (keysym == S || keysym == DOWN)
	{
		new_x = cub3d->player->x - cos(DEG_TO_RAD(cub3d->player->ang)) * cub3d->player->speed;
		new_y = cub3d->player->y - sin(DEG_TO_RAD(cub3d->player->ang)) * cub3d->player->speed;
		if (is_walkable(cub3d, new_x, new_y))
		{
			printf("Entro %d\n", new_y);
			cub3d->player->x = new_x;
			cub3d->player->y = new_y;
		}
		else
			printf("No ntro\n");
	}
	if (old_x != cub3d->player->x || old_y != cub3d->player->y || old_ang != cub3d->player->ang)
		render_frame(cub3d);
	return (0);
}

int	mlx_management(t_cub3d cub3d)
{
	cub3d.mlx = mlx_init();
	if (!cub3d.mlx)
		return (free(cub3d.mlx), free_cub3d(&cub3d), -ERROR_MLX);
	cub3d.window = mlx_new_window(cub3d.mlx, WD, HE, "cub3d");
	if (!cub3d.window)
		return (free(cub3d.mlx), free(cub3d.window),
			free_cub3d(&cub3d), -ERROR_MLX);
	render_frame(&cub3d);
	mlx_key_hook(cub3d.window, &handle_input, &cub3d);
	//mlx_loop_hook(cub3d.mlx, &render_frame, &cub3d);
	mlx_hook(cub3d.window, 17, 1, close_window, &cub3d);
	mlx_loop(cub3d.mlx);
	return (free(cub3d.mlx), free(cub3d.window), 0);
}
