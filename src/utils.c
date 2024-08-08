/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:06:17 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 19:27:09 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handler_map(t_data *map, int error)
{
	if (error == 1)
		(ft_printf("Error: Invalid char in map.\n"), clean(map));
	else if (error == 2)
		(ft_printf("Error: Invalid number of player.\n"), clean(map));
	else if (error == 3)
		(ft_printf("Error: Invalid number of exit.\n"), clean(map));
	else if (error == 4)
		(ft_printf("Error: No collectible in map.\n"), clean(map));
	else if (error == 5)
		(ft_printf("Error: Map is not surrounded by walls.\n"), clean(map));
	else if (error == 6)
		(ft_printf("Error: Map is not a rectangle.\n"), clean(map));
	else if (error == 7)
		(ft_printf("Error: Map is too big.\n"), clean(map));
	else if (error == 8)
		(ft_printf("Error: Map is too small.\n"), clean(map));
	else if (error == 9)
		(ft_printf("Error: Flood check error.\n"), clean(map));
	else if (error > 0)
		(ft_printf("Error code (map): %d.\n", error), clean(map));
	return (1);
}

int	error_handler_loading(t_data *map, int error)
{
	if (!map->mlx || error == 1)
		(ft_printf("Error initializing mlx.\n"), clean(map));
	else if (!map->win || error == 2)
		(ft_printf("Error creating window.\n"), clean(map));
	else if (!map->wall || error == 3)
		(ft_printf("Error loading wall texture.\n"), clean(map));
	else if (!map->tile || error == 4)
		(ft_printf("Error loading tile texture.\n"), clean(map));
	else if (!map->curio || error == 5)
		(ft_printf("Error loading collectible texture.\n"), clean(map));
	else if (!map->exit || error == 6)
		(ft_printf("Error loading exit texture.\n"), clean(map));
	else if (!map->player || error == 7)
		(ft_printf("Error loading player sprite.\n"), clean(map));
	else if (error > 0)
		(ft_printf("Error code (loading): %d.\n", error), clean(map));
	return (1);
}

int	error_handler_file(t_data *map, int error)
{
	if (error == 1)
		(ft_printf("Error opening file.\n"), clean(map));
	else if (error == 2)
		(ft_printf("Error allocating memory.\n"), clean(map));
	else if (error == 3)
		(ft_printf("Error: Invalid map.\n"), clean(map));
	else if (error == 4)
		(ft_printf("Error: Not a compatible file.\n"), clean(map));
	else if (error == 5)
		(ft_printf("Error: Not a \".ber\" extension.\n"), clean(map));
	else if (error > 0)
		(ft_printf("Error code (file): %d.\n", error), clean(map));
	return (1);
}

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

int	clean(t_data *data)
{
	if (!data)
		exit(1);
	if (data->map)
		ft_fsplit(data->map);
	(on_destroy(data), exit(1));
	return (1);
}
