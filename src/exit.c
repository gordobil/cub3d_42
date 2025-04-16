/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:15:33 by ngordobi          #+#    #+#             */
/*   Updated: 2025/04/16 12:15:33 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d->map_path)
		free(cub3d->map_path);
	if (cub3d->map_fd)
		close(cub3d->map_fd);
	return (0);
}

int	error(int code)
{
	if (code == 1)
		ft_printf("Error\nInvalid arguments\n");
	if (code == 2)
		ft_printf("Error\nInvalid map elements\n");
	return (1);
}
