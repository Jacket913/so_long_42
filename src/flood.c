/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:06:43 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 19:53:55 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	flood_map_parse(t_fmap *fmap, t_data *map)
{
	int	i;

	i = -1;
	fmap->c_count = 0;
	fmap->e_count = 0;
	fmap->map = ft_calloc(map->m_y + 1, sizeof(char *));
	if (!fmap->map)
		return (0);
	while (++i < map->m_y)
	{
		fmap->map[i] = ft_strdup(map->map[i]);
		if (!(fmap->map[i]))
			return (ft_fsplit(fmap->map), 0);
	}
	return (1);
}

static void	flood(t_data *map, t_fmap *fmap, int x, int y)
{
	if (x < 0 || y < 0 || x >= map->m_x || y >= map->m_y || fmap->map[y][x] == '1')
		return ;
	else if (map->map[y][x] == 'E')
	{
		++(fmap->e_count);
		fmap->map[y][x] = '1';
		return ;
	}
	else if (map->map[y][x] == 'C')
		++(fmap->c_count);
	fmap->map[y][x] = '1';
	if (y - 1 >= 0 && fmap->map[y - 1][x] != '1')
		flood(map, fmap, x, y - 1);
	if (y + 1 < map->m_y && fmap->map[y + 1][x] != '1')
		flood(map, fmap, x, y + 1);
	if (x - 1 >= 0 && fmap->map[y][x - 1] != '1')
		flood(map, fmap, x - 1, y);
	if (x + 1 < map->m_x && fmap->map[y][x + 1] != '1')
		flood(map, fmap, x + 1, y);
}

int	flood_map(t_data *map)
{
	t_fmap	fmap;

	if (!flood_map_parse(&fmap, map))
		return (0);
	flood(map, &fmap, map->p_x, map->p_y);
	ft_fsplit(fmap.map);
	if (fmap.c_count != map->c_count
		|| fmap.e_count != map->e_count)
		return (0);
	return (1);
}
