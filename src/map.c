/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:15:33 by ngordobi          #+#    #+#             */
/*   Updated: 2025/04/29 12:09:54 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	get_new_map(t_cub3d *cub3d, char **new_map, char *line)
{
	int i;

	i = 0;
	while (cub3d->map[i] != NULL)
	{
		new_map[i] = ft_strdup(cub3d->map[i]);
		i++;
	}
	new_map[i] = ft_substr(line, 0, ft_strlen(line) - 2);
	new_map[i + 1] = NULL;
	if (!new_map || !new_map[i])
		return (free_matrix(new_map), -4);
	return (0);
}

int	get_map(t_cub3d *cub3d, char *line)
{
	static int	i;
	char		**new_map;

	if (!cub3d->map || !cub3d->map[0])
	{
		cub3d->map = malloc(2 * sizeof(char *));
		if (!cub3d->map)
			return (-1);
		cub3d->map[0] = ft_substr(line, 0, ft_strlen(line) - 2);
		if (!cub3d->map[0])
			return (-4);
		cub3d->map[1] = NULL;
		i = 1;
		return (0);
	}
	new_map = malloc((i + 2) * (sizeof(char *)));
	if (!new_map)
		return (-1);
	if (get_new_map(cub3d, new_map, line) != 0)
		return (-1);
	free_matrix(cub3d->map);
	cub3d->map = new_map;
	i++;
	return (0);
}

int	tab_for_spaces(char *new, int k)
{
	new[k] = ' ';
	k++;
	new[k] = ' ';
	k++;
	new[k] = ' ';
	k++;
	new[k] = ' ';
	k++;
	return (k);
}

int	tab_replace(t_cub3d *cub3d)
{
	char	*new;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (cub3d->map[++i] != NULL)
	{
		k = 0;
		j = -1;
		while (cub3d->map[i][++j] != '\0')
			if (cub3d->map[i][j] == '\t')
				k++;
		if (k > 0)
		{
			new = malloc((ft_strlen(cub3d->map[i]) + (k * 4) + 1) * sizeof(char));
			j = 0;
			k = 0;
			while (cub3d->map[i][j] != '\0' && cub3d->map[i][j] != '\n'
				&& cub3d->map[i][j] != '\r')
			{
				if (cub3d->map[i][j] == '\t')
					k = tab_for_spaces(new, k);
				else
				{
					new[k] = cub3d->map[i][j];
					k++;
				}
				j++;
			}
			new[k] = '\0';
			ft_printf("[%d]%S\n", i, new);
			free(cub3d->map[i]);
			cub3d->map[i] = ft_strdup(new);
			free(new);
		}
	}
	return (0);
}

int	check_map(t_cub3d *cub3d)
{
	if (cub3d->map)
		ft_printf("%m\n", cub3d->map);
	tab_replace(cub3d);
	if (cub3d->elements)
		ft_printf("\n%m\n................\n\n", cub3d->elements);
	if (cub3d->map)
		ft_printf("\ntab_replace:\n%m\n", cub3d->map);
	return (0);
}
