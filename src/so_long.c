/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:37:54 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 02:12:58 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac, char **av)
{
	t_data	map;

	if (ac != 2)
		return (ft_printf("Error. Usage: %s <map_file>.\n", av[0]), 1);
	map_init(&map);
	map.mlx = mlx_init();
	if (!map.mlx)
		error_handler_file(&map, 1);
	has_ber_ext(&map, av[1]);
	map_parse(&map, av[1]);
	map_arg_check(&map);
	start_win(&map);
	error_handler_loading(&map, 0);
	draw_win(&map);

	// Register key press hook
	mlx_hook(map.win, KeyPress, KeyPressMask, &on_keypress, &map);

	// Register destroy hook
	mlx_hook(map.win, DestroyNotify, StructureNotifyMask, &on_destroy, &map);

	// Loop over the MLX pointer
	mlx_loop(map.mlx);
	return (0);
}
