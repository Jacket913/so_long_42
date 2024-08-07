/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:38:38 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 00:34:45 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* LIBRARIES */
# include "libft.h"
# include "mlx.h"
#include <stdio.h>
#include <stdlib.h>
#include <X11/X.h>
#include <X11/keysym.h>

/* FUNCTIONS */
typedef struct s_data
{
	char **map;
	int m_x;
	int m_y;
	void *mlx;
	void *win;
	void *wall;
	void *tile;
	void *curio;
	void *exit;
	void *player;
	int p_x;
	int p_y;
	int p_count;
	int e_count;
	int c_count;
	int m_count;
	int c_collected;
} t_data;

void	start_win(t_data *map);
void	map_init(t_data *data);
void	map_parse(t_data *map, char *file);
int		map_limits_check(t_data *map);
int		map_p_check(t_data *map);
int		map_e_check(t_data *map);
int		map_curio_check(t_data *map);
int		map_arg_check(t_data *map);
void	draw_img(t_data *map, char c, int x, int y);
int		draw_win(t_data *map);
void	exit_condition(t_data *map);
void	player_move(t_data *map, int move_y, int move_x);
int		on_destroy(t_data *map);
int		is_valid_char(char c);
int		map_size_check(t_data *map);
int		error_handler_map(int error);
int		error_handler(t_data *map, int error);

#endif
