/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 13:18:42 by ngordobi          #+#    #+#             */
/*   Updated: 2025/04/21 14:40:56 by ngordobi         ###   ########.fr       */
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
	int		ret;

	cub3d = init_cub3d();
	if (argc != 2 || !argv[1] || get_path(argv[1], cub3d) != 0)
		return (free_cub3d(cub3d), error(1));
	ret = check_file(cub3d);
	if (ret < 0)
		return (free_cub3d(cub3d), error(-ret));
	if (cub3d->elements)
		ft_printf("%m", cub3d->elements);
	if (cub3d->map)
		ft_printf("\n%m", cub3d->map);
	return (free_cub3d(cub3d), 0);
}
