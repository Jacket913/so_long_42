/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmoulin <gmoulin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 00:15:37 by gmoulin           #+#    #+#             */
/*   Updated: 2024/08/08 02:08:29 by gmoulin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_valid_char(char c)
{
	return (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C');
}

int	map_size_check(t_data *map)
{
	if (map->m_x < 3 || map->m_y < 3)
		return (6);
	if (map->m_x * 40 > 1280 || map->m_y * 40 > 800)
		return (7);
	if (map->m_x == map->m_y)
		return (8);
	return (1);
}

int	has_ber_ext(t_data *map, const char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len < 4)
		error_handler_file(map, 4);
	if (ft_strncmp(file + len - 4, ".ber", 4) != 0)
		error_handler_file(map, 5);
	return (1);
}
