/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:44:14 by ngordobi          #+#    #+#             */
/*   Updated: 2025/05/01 14:31:46 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	count(char **map, char axis)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
			x++;
	}
	if (axis == 'h')
		return (y);
	else if (axis == 'w')
		return (x);
	return (0);
}

int	flood_fill2(int y, int x, char **map, char pos)
{
	if (map[y][x] == '0' && y < count(map, 'h') && x < count(map, 'w')
		&& y > 0 && x > 0)
		map[y][x] = 'X';
	else if (map[y][x] != pos)
		return (-1);
	if (map[y][x - 1] == '0')
		if (flood_fill(y, x - 1, map, pos) < 0)
			return (-2);
	else if ((x - 1) < 0 || map[y][x - 1] == '\0' || map[y][x - 1] == ' ')
	 	return (-2);
	if (map[y][x + 1] == '0')
		if (flood_fill(y, x + 1, map, pos) < 0)
			return (-3);
	else if ((x + 1) > count(map, 'w') || map[y][x + 1] == '\0' || map[y][x + 1] == ' ')
		return (-3);
	if (map[y - 1][x] == '0')
		if (flood_fill(y - 1, x, map, pos) < 0)
			return (4);
	else if ((y - 1) < 0 || (map[y - 1][x] == '\0' || map[y - 1][x] == ' '))
		return (-4);
	if (map[y + 1][x] == '0')
		if (flood_fill(y + 1, x, map, pos) < 0)
			return (-5);
	else if ((y + 1) > count(map, 'h') || map[y + 1] == NULL || map[y + 1][x] == ' ')
		return (-5);
	return (1);
}

int	flood_fill(int y, int x, char **map, char pos)
{
	//ft_printf("[%d][%d]%c|\n", y, x, map[y][x]);
	if (x < 0 || y < 0 || x > count(map, 'w') || y > count(map, 'h')
		|| map[y][x] == '1' || map[y] == NULL || map[y][x] == '\0')
		return (ft_printf("%m\n", map), 0);
	if ((map[y][x] == '0' && (x == 0 || y == 0 || x == count(map, 'w')
	|| y == count(map, 'h'))) || map[y][x] == ' ')
		return (ft_printf("-1\n"), -1);
	else if ((map[y][x] == '0' || map[y][x] == pos || map[y][x] == 'X')
		&& (map[y][x - 1] == '1' || map[y][x - 1] == '0' || map[y][x - 1] == 'X')
		&& (map[y][x + 1] == '1' || map[y][x + 1] == '0' || map[y][x + 1] == 'X')
		&& (map[y - 1][x] == '1' || map[y - 1][x] == '0' || map[y - 1][x] == 'X')
		&& (map[y + 1][x] == '1' || map[y + 1][x] == '0' || map[y + 1][x] == 'X'))
		map[y][x] = 'X';
	else
		return (ft_printf("-2\n"), -2);
	if (flood_fill(y, x - 1, map, pos) < 0)
		return (ft_printf("-3\n"), -3);
	if (flood_fill(y, x + 1, map, pos) < 0)
		return (ft_printf("-4\n"), -4);
	if (flood_fill(y - 1, x, map, pos) < 0)
		return (ft_printf("-5\n"), -5);
	if (flood_fill(y + 1, x, map, pos) < 0)
		return (ft_printf("-6\n"), -6);
	return (ft_printf("1\n"), 1);
}
