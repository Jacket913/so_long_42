/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 18:37:54 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/07 05:30:28 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_win(t_data *map)
{
	int		w;
	int		h ;
	int	i;
	int	j;

	i = map->map_x;
	j = map->map_y;
	w = 40;
	h = 40;
	map->win = mlx_new_window(map->mlx, i * w, j * h, "so_long gae bowser");
	map->wall = mlx_xpm_file_to_image(map->mlx, "./assets/wall.xpm", &w, &h);
	map->tile = mlx_xpm_file_to_image(map->mlx, "./assets/tile.xpm", &w, &h);
	map->collectible = mlx_xpm_file_to_image(map->mlx, "./assets/coin.xpm", &w, &h);
	map->exit = mlx_xpm_file_to_image(map->mlx, "./assets/exit.xpm", &w, &h);
	map->player = mlx_xpm_file_to_image(map->mlx, "./assets/player.xpm", &w, &h);
}

void	map_init(t_data *data)
{
	data->map = NULL;
	data->map_x = 0;
	data->map_y = 0;
	data->mlx = NULL;
	data->win = NULL;
	data->wall = NULL;
	data->tile = NULL;
	data->collectible = NULL;
	data->exit = NULL;
	data->player = NULL;
	data->p_x = 0;
	data->p_y = 0;
	data->player_count = 0;
	data->exit_count = 0;
	data->collectible_count = 0;
	data->move_count = 0;
	data->collectible_collected = 0;
}


int	on_destroy(t_data *data)
{
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->wall)
		mlx_destroy_image(data->mlx, data->wall);
	if (data->tile)
		mlx_destroy_image(data->mlx, data->tile);
	if (data->collectible)
		mlx_destroy_image(data->mlx, data->collectible);
	if (data->exit)
		mlx_destroy_image(data->mlx, data->exit);
	if (data->player)
		mlx_destroy_image(data->mlx, data->player);
	// if (data->mlx)
	// 	(mlx_destroy_display(data->mlx), free(data->mlx)); doesnt work on mac
	exit (0);
	return (0);
}

int on_keypress(int keysym, t_data *map)
{
	printf("Pressed key: %d\n", keysym);
	if (keysym == 53) // Escape key
		on_destroy(map);
	else if (keysym == 0 || keysym == 123) // Left arrow key
		player_move(map, 'w');
	else if (keysym == 13 || keysym == 126) // Up arrow key
		player_move(map, 'n');
	else if (keysym == 2 || keysym == 124) // Right arrow key
		player_move(map, 'e');
	else if (keysym == 1 || keysym == 125) // Down arrow key
		player_move(map, 's');
	mlx_clear_window(map->mlx, map->win);
	mlx_put_image_to_window(map->mlx, map->win, map->map, 0, 0);
	return (0);
}

void	map_parse(t_data *map, char *file)
{
	int		fd;
	char	*line;
	char	**tmp;
	int		i;

    fd = open(file, O_RDONLY);
    if (fd < 0)
    {
        ft_printf("Error opening file.\n");
        exit(1);
    }
    map->map = NULL;
    map->map_y = 0;
    while ((line = get_next_line(fd)) != NULL)
    {
        tmp = (char **)malloc(sizeof(char *) * (map->map_y + 2));
        if (!tmp)
        {
            ft_printf("Error allocating memory.\n");
            exit(1);
        }
        i = 0;
        while (i < map->map_y)
        {
            tmp[i] = map->map[i];
            i++;
        }
        tmp[i] = line;
        tmp[i + 1] = NULL;
        free(map->map);
        map->map = tmp;
        map->map_y++;
    }
    close(fd);
    if (map->map_y == 0)
    {
		ft_printf("Error, invalid map.\n");
        exit(1);
    }
    map->map_x = ft_strlen(map->map[0]);
}

void	map_draw(t_data *map)
{
	int		i;
	int		j;
	int		w;
    int		h;

    w = 40;
    h = 40;
    if (!map->map)
    {
        ft_printf("Error: map is NULL.\n");
        return;
    }
    i = 0;
    while (map->map[i])
    {
        j = 0;
        while (map->map[i][j])
        {
            if (map->map[i][j] == '1')
                mlx_put_image_to_window(map->mlx, map->win, map->wall, j * w, i * h);
            else if (map->map[i][j] == '0')
                mlx_put_image_to_window(map->mlx, map->win, map->tile, j * w, i * h);
            else if (map->map[i][j] == 'C')
                mlx_put_image_to_window(map->mlx, map->win, map->collectible, j * w, i * h);
            else if (map->map[i][j] == 'E')
                mlx_put_image_to_window(map->mlx, map->win, map->exit, j * w, i * h);
            else if (map->map[i][j] == 'P')
                mlx_put_image_to_window(map->mlx, map->win, map->player, j * w, i * h);
            j++;
        }
        i++;
    }
}

int main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (ft_printf("Error. Usage: %s <map_file>.\n", av[0]), 1);
	map_init(&data);
	data.mlx = mlx_init();
	if (!data.mlx)
		return (ft_printf("Error initializing MLX.\n"), 1);

	map_parse(&data, av[1]);
	map_arg_check(&data);
	start_win(&data);

	if (!data.win)
		ft_printf("Error creating window.\n");
	if (!data.wall)
		ft_printf("Error loading wall texture.\n");
	if (!data.tile)
		ft_printf("Error loading tile texture.\n");
	if (!data.collectible)
		ft_printf("Error loading collectible texture.\n");
	if (!data.exit)
		ft_printf("Error loading exit texture.\n");
	if (!data.player)
		ft_printf("Error loading player texture.\n");

	map_draw(&data);


	// Register key press hook
	mlx_hook(data.win, KeyPress, KeyPressMask, &on_keypress, &data);

	// Register destroy hook
	mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &on_destroy, &data);

	// Loop over the MLX pointer
	mlx_loop(data.mlx);
	return (0);
}

/*if (all_collectables_collected && exit_count == 1)
	return map_valid;
if (on_wall)
	return map_invalid;
if (on_collectable)
	collectables++;
if (on_exit)
	exits++;
replace_current_position_with_wall;
if (one_of_the_four_adjacent_directions_is_possible)
	return map_valid;
return map_invalid;*/
