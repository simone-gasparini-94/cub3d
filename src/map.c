/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:39:31 by duccello          #+#    #+#             */
/*   Updated: 2025/12/01 11:52:47 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "map.h"
#include "data.h"
#include "libft.h"
#include <stdbool.h>
#include <sys/types.h>

static bool	flood_check(char **map, int x, int y, int rows);
static bool	player_check(t_map *map);

bool	map_check(t_data *data)
{
	if (player_check(data->map) == false)
		return (false);
	if (flood_check(flood_map, data->map.x, data->map.y, data->map.rows) == false)
		return (false);
}

static bool	flood_check(char **map, int x, int y, int rows)
{
	int	cols;

	cols = ft_strlen(map[y]);
	if (x < 0 || x > cols)
		return (true);
	if (y < 0 || y > rows)
		return (true);
	if (map[y][x] == 0)
	{
		if (y == 0 || x == 0 || x == cols || y == rows)
			return (false);
		else if (map[x][y - 1] == ' ' || map[x][y + 1] == ' ')
			return (false);
		else if (map[x + 1][y] == ' ' || map[x - 1][y] == ' ')
			return (false);
	}
	flood_check(map, x + 1, y, cols);
	flood_check(map, x - 1, y, cols);
	flood_check(map, x, y + 1, cols);
	flood_check(map, x, y - 1, cols);
	return (true);
}

static bool	player_check(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	p = 0;
	while (i < map->rowss)
	{
		j = 0;
		while (map->m[i][j] != '\0')
		{
			if (map->m[i][j] == 'N' || map->m[i][j] == 'S'
				|| map->m[i][j] == 'E' || map->m[i][j] == 'W')
			{
				map->player == map->m[i][j];
				p++;
				map->x = i;
				map->y = j;
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		return (false);
	return (true);
}
