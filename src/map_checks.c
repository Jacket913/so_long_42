/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 01:05:31 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 00:33:33 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_limits_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->m_y)
	{
		j = 0;
		while (j < map->m_x)
		{
			if (map->map[i][j] != '1' && (i == 0 || i == map->m_y - 1))
				return (0);
			if (map->map[i][j] != '1' && (j == 0 || j == map->m_x - 1))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	map_p_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->m_y - 1)
	{
		j = 0;
		while (++j < map->m_x - 1)
		{
			if (map->map[i][j] == 'P')
			{
				if (map->p_count == 1)
					return (0);
				map->p_count++;
				map->p_x = j;
				map->p_y = i;
			}
		}
	}
	if (map->p_count == 0)
		return (0);
	return (1);
}

int	map_e_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->m_y - 1)
	{
		j = 0;
		while (++j < map->m_x - 1)
		{
			if (map->map[i][j] == 'E')
			{
				if (map->e_count == 1)
					return (0);
				map->e_count++;
			}
		}
	}
	if (map->e_count == 0)
		return (0);
	return (1);
}

int	map_curio_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->m_y - 1)
	{
		j = 0;
		while (++j < map->m_x - 1)
		{
			if (map->map[i][j] == 'C')
				map->c_count++;
		}
	}
	if (map->c_count == 0)
		return (0);
	return (1);
}

int	map_arg_check(t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (++i < map->m_y - 1)
	{
		j = 0;
		while (++j < map->m_x - 1)
		{
			if (!is_valid_char(map->map[i][j]))
				return (error_handler_map(1), 0);
		}
	}
	if (!map_p_check(map))
		return (error_handler_map(2), 0);
	if (!map_e_check(map))
		return (error_handler_map(3), 0);
	if (!map_curio_check(map))
		return (error_handler_map(4), 0);
	if (!map_limits_check(map))
		return (error_handler_map(5), 0);
	if (map_size_check(map) != 1)
		return (error_handler_map(map_size_check(map)));
	return (1);
}
