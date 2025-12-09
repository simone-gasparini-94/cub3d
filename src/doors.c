/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 17:42:37 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/09 18:27:32 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

#define LETTERS 26

static void find_next_area(char **map, size_t *y, size_t *x, char c);
static void fill_area(char  **map, char c, size_t y, size_t x, t_data *data);
static void	find_vertical_walls(t_map *map);
static void	find_horizontal_walls(t_map *map);
static void	create_door(char **map, size_t y, size_t x, char c, bool *door_created, int rand);
static void	clean_map(t_map *map);

void    set_doors(t_data *data)
{
    char    area_char;
	char	index_char;
    size_t  y;
    size_t  x;
	bool	door_created;

    data->map.map = copy_matrix(data);
    area_char = 'a';
    y = 1;
    x = 1;
    while (data->map.empty_spaces > 0 && area_char < 'z')
    {
        find_next_area(data->map.map, &y, &x, '0');
        fill_area(data->map.map, area_char, y, x, data);
        area_char++;
    }
	find_vertical_walls(&data->map);
	find_horizontal_walls(&data->map);
	y = 1;
	x = 1;
	index_char = 'a';
	while (index_char < area_char - 1)
	{
		door_created = false;
		find_next_area(data->map.map, &y, &x, index_char);
		create_door(data->map.map, y, x, index_char, &door_created, 1);
		index_char++;
	}
	clean_map(&data->map);
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

static void	create_door(char **map, size_t y, size_t x, char c, bool *door_created, int rand)
{
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
	map[y][x] = 'z';
	if (rand % 2 == 0)
	{
		create_door(map, y + 1, x, c, door_created, rand + 1);
		create_door(map, y, x + 1, c, door_created, rand + 1);
		create_door(map, y - 1, x, c, door_created, rand + 1);
		create_door(map, y, x - 1, c, door_created, rand + 1);
	}
	else
	{
		create_door(map, y, x + 1, c, door_created, rand + 1);
		create_door(map, y + 1, x, c, door_created, rand + 1);
		create_door(map, y, x - 1, c, door_created, rand + 1);
		create_door(map, y - 1, x, c, door_created, rand + 1);
	}
}

static void find_next_area(char **map, size_t *y, size_t *x, char c)
{
    while (map[*y] != NULL)
    {
        *x = 1;
        while (map[*y][*x])
        {
            if (map[*y][*x] == c)
                return ;
            (*x)++;
        }   
        (*y)++;
    }
}

static void fill_area(char  **map, char c, size_t y, size_t x, t_data *data)
{
    if (map[y][x] == '1' || map[y][x] == c)
        return ;
    if (ft_isalpha(map[y][x]) == true && map[y][x] < c)
        return ;
    map[y][x] = c;
    data->map.empty_spaces--;
    fill_area(map, c, y + 1, x, data);
    fill_area(map, c, y, x + 1, data);
    fill_area(map, c, y - 1, x, data);
    fill_area(map, c, y, x - 1, data);
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
