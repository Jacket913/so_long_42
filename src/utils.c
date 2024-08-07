/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:06:17 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 00:28:16 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_handler_map(int error)
{
	if (error == 1)
		return(ft_printf("Error: Invalid char in map.\n"), 0);
	if (error == 2)
		return(ft_printf("Error: Invalid number of player.\n"), 0);
	if (error == 3)
		return(ft_printf("Error: Invalid number of exit.\n"), 0);
	if (error == 4)
		return(ft_printf("Error: No collectible in map.\n"), 0);
	if (error == 5)
		return(ft_printf("Error: Map is not surrounded by walls.\n"), 0);
	if (error == 6)
		return(ft_printf("Error: Map is not a rectangle.\n"), 0);
	if (error == 7)
		return(ft_printf("Error: Map is too big.\n"), 0);
	if (error == 8)
		return(ft_printf("Error: Map is too small.\n"), 0);
	else if (error < 0)
		return(ft_printf("Error code (map): %d.\n", error), 0);
	return (1);
}

int	error_handler(t_data *map, int error)
{
	if (!map->win)
		return(ft_printf("Error creating window.\n"), 0);
	if (!map->wall)
		return(ft_printf("Error loading wall texture.\n"), 0);
	if (!map->tile)
		return(ft_printf("Error loading tile texture.\n"), 0);
	if (!map->curio)
		return(ft_printf("Error loading collectible texture.\n"), 0);
	if (!map->exit)
		return(ft_printf("Error loading exit texture.\n"), 0);
	if (!map->player)
		return(ft_printf("Error loading player sprite.\n"), 0);
	else if (error < 0)
		return(ft_printf("Error code (map): %d.\n", error), 0);
	return (1);
}
