/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:51:16 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/07 05:26:07 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	player_move(t_data *map, char c)
{
	if (!map || !map->map) {
        ft_printf("Error: map or map->map is NULL\n");
        return;
    }

    ft_printf("Player position before move: (%d, %d)\n", map->p_y, map->p_x);
    ft_printf("Move command: %c\n", c);

	if (c == 'n' && map->p_y > 0)
	{
		if (map->map[map->p_y - 1][map->p_x] == '0')
		{
			map->map[map->p_y][map->p_x] = '0';
			map->p_y--;
			map->map[map->p_y][map->p_x] = 'P';
			map->move_count++;
		}
	}
	if (c == 's' && map->p_y < map->map_y - 1)
	{
		if (map->map[map->p_y + 1][map->p_x] == '0')
		{
			map->map[map->p_y][map->p_x] = '0';
			map->p_y++;
			map->map[map->p_y][map->p_x] = 'P';
			map->move_count++;
		}
	}
	if (c == 'w'  && map->p_x > 0)
	{
		if (map->map[map->p_y][map->p_x - 1] == '0')
		{
			map->map[map->p_y][map->p_x] = '0';
			map->p_x--;
			map->map[map->p_y][map->p_x] = 'P';
			map->move_count++;
		}
	}
	if (c == 'e' && map->p_x < map->map_x - 1)
	{
		if (map->map[map->p_y][map->p_x + 1] == '0')
		{
			map->map[map->p_y][map->p_x] = '0';
			map->p_x++;
			map->map[map->p_y][map->p_x] = 'P';
			map->move_count++;
		}
	}
	ft_printf("Player position after move: (%d, %d)\n", map->p_y, map->p_x);
    ft_printf("Move count: %d\n", map->move_count);
}
