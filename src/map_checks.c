/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:05:31 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/07 05:21:18 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_limits_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_y)
	{
		j = 0;
		while (j < map->map_x)
		{
			if (map->map[i][j] != '1' && (i == 0 || i == map->map_y - 1))
				return (0);
			if (map->map[i][j] != '1' && (j == 0 || j == map->map_x - 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_pe_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->map_y - 1)
	{
		j = 0;
		while (++j < map->map_x - 1)
		{
			if (map->map[i][j] == 'P')
			{
				if (map->player_count == 1)
					return (0);
				map->player_count++;
				map->p_x = j;
				map->p_y = i;
			}
			if (map->map[i][j] == 'E')
			{
				if (map->exit_count == 1)
					return (0);
				map->exit_count++;
			}
		}
	}
	return (1);
}

int	map_collectible_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->map_y - 1)
	{
		j = 0;
		while (++j < map->map_x - 1)
		{
			if (map->map[i][j] == 'C')
				map->collectible_count++;
		}
	}
	return (1);
}

int	map_arg_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->map_y - 1)
	{
		j = 0;
		while (++j < map->map_x - 1)
		{
			if (map->map[i][j] != '1' && map->map[i][j] != '0' &&
				map->map[i][j] != 'P' && map->map[i][j] != 'E' &&
				map->map[i][j] != 'C')
				return (0);
		}
	}
	if (!map_pe_check(map) || !map_collectible_check(map))
		ft_printf("Error, invalid map.\n");
		return (0);
	return (1);
}
