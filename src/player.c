/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:51:16 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/18 13:13:40 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_keypress(int keysym, t_data *map)
{
	if (keysym == 65307)
		clean(map);
	else if (keysym == 97 || keysym == 65361)
	{
		player_move(map, 0, -1);
		ft_printf("Move : West.\n");
	}
	else if (keysym == 119 || keysym == 65362)
	{
		player_move(map, -1, 0);
		ft_printf("Move : North.\n");
	}
	else if (keysym == 100 || keysym == 65363)
	{
		player_move(map, 0, 1);
		ft_printf("Move : East.\n");
	}
	else if (keysym == 115 || keysym == 65364)
	{
		player_move(map, 1, 0);
		ft_printf("Move : South.\n");
	}
	mlx_clear_window(map->mlx, map->win);
	draw_win(map);
	return (0);
}

void	exit_condition(t_data *map)
{
	if (map->c_collected == map->c_count)
	{
		map->m_count++;
		ft_printf("You win!\n");
		ft_printf("Move count: %d\n", map->m_count);
		clean(map);
		exit(0);
	}
	else if (map->c_collected != map->c_count)
		ft_printf("You need all of Max's Lugers before going to Sam.\
		\nLugers collected: %d/%d.\n", map->c_collected, map->c_count);
}

void	player_move(t_data *map, int move_y, int move_x)
{
	if (map->map[map->p_y + move_y][map->p_x + move_x] != '1')
	{
		if (map->map[map->p_y + move_y][map->p_x + move_x] == 'E')
		{
			exit_condition(map);
			return ;
		}
		if (map->map[map->p_y + move_y][map->p_x + move_x] == 'C')
			map->c_collected++;
		map->map[map->p_y][map->p_x] = '0';
		map->p_y += move_y;
		map->p_x += move_x;
		map->map[map->p_y][map->p_x] = 'P';
		map->m_count++;
	}
	else
		ft_printf("You can't just run through walls, Max...\n");
	ft_printf("Move count: %d\n", map->m_count);
	ft_printf("Lugers collected: %d/%d\n", map->c_collected, map->c_count);
}
