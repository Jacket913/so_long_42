/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:51:16 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/07 22:31:58 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	exit_condition(t_data *map)
{
	if (map->c_collected == map->c_count)
	{
		map->m_count++;
		ft_printf("You win!\n");
		ft_printf("Move count: %d\n", map->m_count);
		on_destroy(map);
		exit(0);
	}
	else if (map->c_collected != map->c_count)
		ft_printf("You need all collectibles to open the exit.\nCollectibles collected: %d/%d.\n",map->c_collected, map->c_count);
}

void	player_move(t_data *map, int move_y, int move_x)
{
	if (map->map[map->p_y + move_y][map->p_x + move_x] != '1')
	{
		if (map->map[map->p_y + move_y][map->p_x + move_x] == 'E')
		{
			exit_condition(map);
			return;
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
		ft_printf("You can't just run through walls...\n");
	ft_printf("Move count: %d\n", map->m_count);
	ft_printf("Collectible collected: %d/%d\n", map->c_collected, map->c_count);
}

