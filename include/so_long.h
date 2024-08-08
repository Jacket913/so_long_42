/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:38:38 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 19:40:31 by gmoulin          ###   ########.fr       */
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
	char	**map;
	int		m_x;
	int		m_y;
	void	*mlx;
	void	*win;
	void	*wall;
	void	*tile;
	void	*curio;
	void	*exit;
	void	*player;
	int		p_x;
	int		p_y;
	int		p_count;
	int		e_count;
	int		c_count;
	int		m_count;
	int		c_collected;
} t_data;

typedef struct s_fmap
{
	char	**map;
	int		c_count;
	int		e_count;
}	t_fmap;

// checks1.c
int			map_limits_check(t_data *map);
int			map_p_check(t_data *map);
int			map_e_check(t_data *map);
int			map_curio_check(t_data *map);
int			map_arg_check(t_data *map);

// checks2.c
int			is_valid_char(char c);
int			map_size_check(t_data *map);
int			has_ber_ext(t_data *map, const char *file);

// flood.c
int			flood_map(t_data *map);

// game_init.c
void		start_win(t_data *map);
void		map_init(t_data *data);
void		map_parse(t_data *map, char *file);

// map_draw.c
void		draw_img(t_data *map, char c, int x, int y);
int			draw_win(t_data *map);

//player.c
int			on_keypress(int keysym, t_data *map);
void		exit_condition(t_data *map);
void		player_move(t_data *map, int move_y, int move_x);

// utils.c
int			error_handler_map(t_data *map, int error);
int			error_handler_loading(t_data *map, int error);
int			error_handler_file(t_data *map, int error);
int			on_destroy(t_data *map);
int			clean(t_data *data);

#endif
