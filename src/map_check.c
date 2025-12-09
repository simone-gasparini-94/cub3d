/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:39:31 by duccello          #+#    #+#             */
/*   Updated: 2025/12/09 15:40:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "data.h"
#include "libft.h"
#include "map.h"
#include "parse.h"
#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>

static bool	wall_check(t_data *data, char **map, int rows, char player_char);
static bool	player_check(t_data *data);

bool	map_check(t_data *data)
{
	if (player_check(data) == false)
		return (false);
	if (wall_check(data, data->map.matrix, data->map.rows,
			data->map.player_char) == false)
		return (false);
	return (true);
}

static bool	wall_check(t_data *data, char **map, int rows, char player_char)
{
	int	cols;
	int	x;
	int y;

	y = 0;
	while (y < rows)
	{
		cols = ft_strlen(map[y]);
		x = 0;
		while (x < cols)
		{
			if (map[y][x] == '0' || map[y][x] == player_char)
			{
				if (y == 0 || x == 0 || x == cols - 1 || y == rows - 1 
					|| map[y][x + 1] == ' ' || map[y][x - 1] == ' '
					|| map[y][x + 1] == '\0' || map[y + 1][x] == ' ' 
					|| map[y - 1][x] == ' ')
				{
					data->file_line += y;
					return (false);
				}
			}
			x++;
		}
		y++;
	}
	return (true);
}

static bool	player_check(t_data *data)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	p = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (data->map.matrix[i][j] != '\0')
		{
			if (data->map.matrix[i][j] == 'N' || data->map.matrix[i][j] == 'S'
				|| data->map.matrix[i][j] == 'E'
				|| data->map.matrix[i][j] == 'W')
			{
				data->map.player_char = data->map.matrix[i][j];
				p++;
				if (p > 1)
				{
					data->file_line += i;
					return (false);
				}
				data->map.player_x = j;
				data->map.player_y = i;
			}
			j++;
		}
		i++;
	}
	return (p == 1);
}
