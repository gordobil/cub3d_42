/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngordobi <ngordobi@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:59:40 by ngordobi          #+#    #+#             */
/*   Updated: 2024/01/28 18:14:19 by ngordobi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <sys/stat.h>
# include <sys/time.h>
# include "../mlx/mlx.h"
# include "./libft.h"

//COLORS
# define BLUE "\033[1;34m"
# define YELLOW "\033[0;32m"
# define WHITE "\033[0m"

typedef struct s_cub3d
{
	char		*map_path;
	int			map_fd;
	char		**map;
	char		**elements;
}				t_cub3d;

/******************************** PARSING ********************************/
//EXIT
int	free_matrix(char **matrix);
int	free_cub3d(t_cub3d *cub3d);
int	error(int code);

//FILES
int	get_path(char *path, t_cub3d *cub3d);
int	check_file(t_cub3d *cub3d);

//UTILS
int	jump_empty(char *line, int i);
int	get_elem_length(int i, char *line);

//MAP
int	get_map(t_cub3d *cub3d, char *line);
int	check_map(t_cub3d *cub3d);

#endif
