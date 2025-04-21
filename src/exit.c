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

int	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return (-1);
	i = -1;
	while (matrix[++i] != NULL)
	{
		if (matrix[i])
			free(matrix[i]);
		matrix[i] = NULL;
	}
	free(matrix);
	matrix = NULL;
	return (0);
}

int	free_cub3d(t_cub3d *cub3d)
{
	if (cub3d->map_path != NULL)
		free(cub3d->map_path);
	if (cub3d->map_fd)
		close(cub3d->map_fd);
	if (cub3d->elements)
		free_matrix(cub3d->elements);
	if (cub3d)
		free(cub3d);
	return (0);
}

int	error(int code)
{
	if (code == 1)
		ft_printf("Error\nInvalid arguments\n");
	if (code == 2)
		ft_printf("Error\nInvalid map elements\n");
	if (code == 3)
		ft_printf("Error\nInvalid map\n");
	return (1);
}
