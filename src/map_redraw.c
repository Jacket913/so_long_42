/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_redraw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 19:22:37 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/07 19:29:38 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw_img(t_data *map, char c, int x, int y)
{
	if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->wall, x, y);
	else if (c == 'P')
		mlx_put_image_to_window(map->mlx, map->win, map->player, x, y);
	else if (c == 'C')
		mlx_put_image_to_window(map->mlx, map->win, map->collectible, x, y);
	else if (c == 'E')
		mlx_put_image_to_window(map->mlx, map->win, map->exit, x, y);
	else if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->tile, x, y);
}

int	redraw_win(t_data *map, int x, int y)
{
	int	i;
	int	j;
	int		start_x;
	int		start_y;

	start_x = x;
	start_y = y;
	i = 0;
	j = 0;
	while (i < map->map_y)
	{
		while (map->map[i][j])
		{
			redraw_img(map, map->map[i][j], start_x, start_y);
			j++;
			start_x += 40;
		}
		j = 0;
		start_x = x;
		i++;
		start_y += 40;
	}
	return (0);
}
