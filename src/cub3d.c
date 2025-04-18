/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:18:42 by ngordobi          #+#    #+#             */
/*   Updated: 2025/04/18 13:48:11 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

t_cub3d	*init_cub3d(void)
{
	t_cub3d	*cub3d;

	cub3d = malloc(sizeof(t_cub3d));
	cub3d->map_fd = 0;
	cub3d->elements = malloc(7 * sizeof(char *));
	return (cub3d);
}

int	main(int argc, char **argv)
{
	t_cub3d	*cub3d;

	cub3d = init_cub3d();
	if (argc != 2 || !argv[1] || get_path(argv[1], cub3d) != 0)
		return (free_cub3d(cub3d), error(1));
	if (check_file(cub3d) == -1)
		return (free_cub3d(cub3d), error(2));
	return (0);
}
