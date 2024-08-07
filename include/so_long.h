/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:38:38 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/07 20:14:23 by gmoulin          ###   ########.fr       */
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
	int map_x;
	int map_y;
	void *mlx;
	void *win;
	void *wall;
	void *tile;
	void *collectible;
	void *exit;
	void *player;
	int p_x;
	int p_y;
	int player_count;
	int exit_count;
	int collectible_count;
	int move_count;
	int collectible_collected;
} t_data;

void	start_win(t_data *map);
void	map_init(t_data *data);
int		on_destroy(t_data *data);
int		map_limits_check(t_data *map);
int		map_pe_check(t_data *map);
int		map_collectible_check(t_data *map);
int		map_arg_check(t_data *map);
void 	exit_condition(t_data *map);
void	player_move(t_data *map, int move_y, int move_x);
void	redraw_img(t_data *map, char c, int x, int y);
int		redraw_win(t_data *map, int x, int y);

#endif
