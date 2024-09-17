/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/07 23:35:53 by gmoulin           #+#    #+#             */
/*   Updated: 2024/09/17 16:00:57 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_win(t_data *map)
{
	int		w;
	int		h ;
	int		i;
	int		j;
	char	*windowtitle;

	windowtitle = "You crack me up, little buddy!";
	i = map->m_x;
	j = map->m_y;
	w = 40;
	h = 40;
	map->win = mlx_new_window(map->mlx, i * w, j * h, windowtitle);
	map->wall = mlx_xpm_file_to_image(map->mlx, "./assets/wall.xpm", &w, &h);
	map->tile = mlx_xpm_file_to_image(map->mlx, "./assets/tile.xpm", &w, &h);
	map->curio = mlx_xpm_file_to_image(map->mlx, "./assets/coin.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./assets/exit.xpm", &w, &h);
	map->player = mlx_xpm_file_to_image(map->mlx, "./assets/max.xpm", &w, &h);
}

void	map_init(t_data *map)
{
	map->map = NULL;
	map->m_x = 0;
	map->m_y = 0;
	map->mlx = NULL;
	map->win = NULL;
	map->wall = NULL;
	map->tile = NULL;
	map->curio = NULL;
	map->exit = NULL;
	map->player = NULL;
	map->p_x = 0;
	map->p_y = 0;
	map->p_count = 0;
	map->e_count = 0;
	map->c_count = 0;
	map->m_count = 0;
	map->c_collected = 0;
}

void	map_parse(t_data *map, char *file)
{
	int		fd;
	char	*line;
	char	**tmp;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		error_handler_file(map, 1);
	while (oget_next_line(fd, &line) != NULL)
	{
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		tmp = (char **)malloc(sizeof(char *) * (map->m_y + 2));
		if (!tmp)
			error_handler_file(map, 2);
		ft_memcpy(tmp, map->map, sizeof(char *) * map->m_y);
		tmp[map->m_y++] = ft_strdup(line);
		tmp[map->m_y] = NULL;
		(free(map->map), map->map = tmp);
		free(line);
	}
	(close(fd), map->m_x = ft_strlen(map->map[0]));
	if (map->m_y == 0 || map->m_x == 0)
		error_handler_file(map, 3);
}
