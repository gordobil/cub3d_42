/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:44:14 by ngordobi          #+#    #+#             */
/*   Updated: 2025/05/07 17:02:50 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	free_matrix(char **matrix)
{
	int	i;

	if (!matrix)
		return (-1);
	i = -1;
	while (matrix[++i])
	{
		if (matrix[i])
			free(matrix[i]);
	}
	if (matrix)
		free(matrix);
	return (0);
}
