/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:37:20 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 11:43:37 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "map.h"
#include "utils.h"
#include "libft.h"
#include "print.h"
#include <stdlib.h>
#include <stdio.h>

static void	find_vertical_walls(t_map *map);
static void	find_horizontal_walls(t_map *map);

void	find_eligible_walls(t_map *map)
{
	find_vertical_walls(map);
	find_horizontal_walls(map);
}

static void	find_vertical_walls(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 1;
	while (y < map->rows - 1)
	{
		x = 1;
		while (x < map->cols - 1)
		{
			if (map->map[y][x] == '1'
				&& ft_islowercase(map->map[y][x - 1])
				&& ft_islowercase(map->map[y][x + 1])
				&& map->map[y][x - 1] != map->map[y][x + 1])
					map->map[y][x] = ft_toupper(map->map[y][x - 1]);
			x++;
		}
		y++;
	}
}

static void	find_horizontal_walls(t_map *map)
{
	size_t	x;
	size_t	y;

	x = 1;
	while (x < map->cols - 1)
	{
		y = 1;
		while (y < map->rows - 1)
		{
			if (map->map[y][x] == '1'
				&& ft_islowercase(map->map[y - 1][x])
				&& ft_islowercase(map->map[y + 1][x])
				&& map->map[y - 1][x] != map->map[y + 1][x])
					map->map[y][x] = ft_toupper(map->map[y - 1][x]);
			y++;
		}
		x++;
	}
}
