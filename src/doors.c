/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:37 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 11:44:34 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "map.h"
#include "utils.h"
#include "libft.h"
#include "print.h"
#include <stdlib.h>
#include <stdio.h>

static void	create_door(char **map, size_t y, size_t x, char c, bool *door_created);
static void	clean_map(t_map *map);

void    set_doors(t_data *data)
{
    char    area_char;
	char	index_char;
    size_t  y;
    size_t  x;
	bool	door_created;

	print_map(data, MATRIX);
    data->map.map = copy_matrix(data);
    area_char = 'a';
	find_enclosed_areas(data, &area_char);
	find_eligible_walls(&data->map);
	y = 1;
	x = 1;
	index_char = 'a';
	while (index_char < area_char - 1)
	{
		door_created = false;
		find_next_area(data->map.map, &y, &x, index_char);
		create_door(data->map.map, y, x, index_char, &door_created);
		index_char++;
	}
	print_map(data, MAP);
	clean_map(&data->map);
	print_map(data, MAP);
}

static void	clean_map(t_map *map)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (ft_islowercase(map->map[y][x]))
				map->map[y][x] = '0';
			else if (ft_isuppercase(map->map[y][x]))
				map->map[y][x] = '1';
			x++;
		}
		y++;
	}
}

static void	create_door(char **map, size_t y, size_t x, char c, bool *door_created)
{
	size_t	hash;

	if (map[y][x] == '1' || map[y][x] == 'z')
		return ;
	if (*door_created == true)
		return ;
	if (map[y][x] == ft_toupper(c))
	{
		map[y][x] = '\\';
		*door_created = true;
		return ;
	}
	if (map[y][x] == c)
		map[y][x] = 'z';
	else
		return ;
	hash = y ^ x + c;	
	if (hash % 4 == 0)
	{
		create_door(map, y, x + 1, c, door_created);
		create_door(map, y + 1, x, c, door_created);
		create_door(map, y - 1, x, c, door_created);
		create_door(map, y, x - 1, c, door_created);
	}
	else if (hash % 4 == 1)
	{	
		create_door(map, y, x - 1, c, door_created);
		create_door(map, y, x + 1, c, door_created);
		create_door(map, y + 1, x, c, door_created);
		create_door(map, y - 1, x, c, door_created);
	}
	else if (hash % 4 == 2)
	{	
		create_door(map, y + 1, x, c, door_created);
		create_door(map, y, x + 1, c, door_created);
		create_door(map, y, x - 1, c, door_created);
		create_door(map, y - 1, x, c, door_created);
	}
	else
	{
		create_door(map, y, x + 1, c, door_created);
		create_door(map, y, x - 1, c, door_created);
		create_door(map, y - 1, x, c, door_created);
		create_door(map, y + 1, x, c, door_created);
	}
}

