/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 04:51:16 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/07 20:30:17 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

void	exit_condition(t_data *map)
{
	if (map->collectible_collected == map->collectible_count)
	{
		map->move_count++;
		ft_printf("You win!\n");
		ft_printf("Move count: %d\n", map->move_count);
		on_destroy(map);
		exit(0);
	}
	else if (map->collectible_collected != map->collectible_count)
		ft_printf("You need all collectibles to open the exit.\nCollectibles collected: %d/%d.\n",map->collectible_collected, map->collectible_count);
}

void	player_move(t_data *map, int move_y, int move_x)
{
	if (!map || !map->map) {
		ft_printf("Error: map or map->map is NULL\n");
		return;
	}
	ft_printf("Player position before move: (%d, %d)\n", map->p_y, map->p_x);

	if (map->map[map->p_y + move_y][map->p_x + move_x] != '1')
	{
		if (map->map[map->p_y + move_y][map->p_x + move_x] == 'E')
		{
			exit_condition(map);
			return;
		}
		if (map->map[map->p_y + move_y][map->p_x + move_x] == 'C')
			map->collectible_collected++;
		map->map[map->p_y][map->p_x] = '0';
		map->p_y += move_y;
		map->p_x += move_x;
		map->map[map->p_y][map->p_x] = 'P';
		map->move_count++;
	}
	else
		ft_printf("You can't just run through walls...\n");
	ft_printf("Player position after move: (%d, %d)\n", map->p_y, map->p_x);
	ft_printf("Move count: %d\n", map->move_count);
	ft_printf("Collectible collected: %d/%d\n", map->collectible_collected, map->collectible_count);
}

