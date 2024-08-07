/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:37:54 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 00:41:06 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	on_destroy(t_data *map)
{
	if (map->win)
		mlx_destroy_window(map->mlx, map->win);
	if (map->wall)
		mlx_destroy_image(map->mlx, map->wall);
	if (map->tile)
		mlx_destroy_image(map->mlx, map->tile);
	if (map->curio)
		mlx_destroy_image(map->mlx, map->curio);
	if (map->exit)
		mlx_destroy_image(map->mlx, map->exit);
	if (map->player)
		mlx_destroy_image(map->mlx, map->player);
	// if (map->mlx)
	// 	(mlx_destroy_display(map->mlx), free(map->mlx)); doesnt work on mac
	exit (0);
	return (0);
}

int on_keypress(int keysym, t_data *map)
{
	if (keysym == 53) // Escape key
		on_destroy(map);
	else if (keysym == 0 || keysym == 123) // Left arrow key
	{
		player_move(map, 0, -1);
		ft_printf("Move : West.\n");
	}
	else if (keysym == 13 || keysym == 126) // Up arrow key
	{
		player_move(map, -1, 0);
		ft_printf("Move : North.\n");
	}
	else if (keysym == 2 || keysym == 124) // Right arrow key
	{
		player_move(map, 0, 1);
		ft_printf("Move : East.\n");
	}
	else if (keysym == 1 || keysym == 125) // Down arrow key
	{
		player_move(map, 1, 0);
		ft_printf("Move : South.\n");
	}
	mlx_clear_window(map->mlx, map->win);
	draw_win(map);
	return (0);
}

int main(int ac, char **av)
{
	t_data	map;

	if (ac != 2)
		return (ft_printf("Error. Usage: %s <map_file>.\n", av[0]), 1);
	map_init(&map);
	map.mlx = mlx_init();
	if (!map.mlx)
		return (ft_printf("Error initializing MLX.\n"), 1);
	map_parse(&map, av[1]);
	if (!map_arg_check(&map))
		return (1);
	start_win(&map);
	if (!error_handler(&map, 0))
		return (1);
	draw_win(&map);

	// Register key press hook
	mlx_hook(map.win, KeyPress, KeyPressMask, &on_keypress, &map);

	// Register destroy hook
	mlx_hook(map.win, DestroyNotify, StructureNotifyMask, &on_destroy, &map);

	// Loop over the MLX pointer
	mlx_loop(map.mlx);
	return (0);
}
