/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:45:27 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/08 13:23:53 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "destroy.h"
#include "graphic.h"
#include <X11/keysym.h>
#include <stdio.h>

static void	move_forward(t_data *data);
static void	move_backwards(t_data *data);
static void	move_left(t_data *data);
static void	move_right(t_data *data);
static void	turn_left(t_data *data);
static void	turn_right(t_data *data);

int	handle_key_presses(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit(data);
	if (keysym == XK_W || keysym == XK_w)
	{
		move_forward(data);
		render(data);
	}
	if (keysym == XK_S || keysym == XK_s)
	{
		move_backwards(data);
		render(data);
	}
	if (keysym == XK_A || keysym == XK_a)
	{
		move_left(data);
		render(data);
	}
	if (keysym == XK_D || keysym == XK_d)
	{
		move_right(data);
		render(data);
	}
	if (keysym == XK_Left)
	{
		turn_left(data);
		render(data);
	}
	if (keysym == XK_Right)
	{
		turn_right(data);
		render(data);
	}
	return (0);
}

static void	move_forward(t_data *data)
{
	t_map *map;

	map = &data->map;
	if (map->player_char == 'N' && map->matrix[map->player_y - 1][map->player_x] != '1')
		data->map.player_y--;
	else if (map->player_char == 'S' && map->matrix[map->player_y + 1][map->player_x] != '1')
		data->map.player_y++;
	else if (map->player_char == 'E' && map->matrix[map->player_y][map->player_x + 1] != '1')
		data->map.player_x++;
	else if (map->player_char == 'W' && map->matrix[map->player_y][map->player_x - 1] != '1')
		data->map.player_x--;
}

static void	move_backwards(t_data *data)
{
	t_map *map;

	map = &data->map;
	if (map->player_char == 'N' && map->matrix[map->player_y + 1][map->player_x] != '1')
		data->map.player_y++;
	else if (map->player_char == 'S' && map->matrix[map->player_y - 1][map->player_x] != '1')
		data->map.player_y--;
	else if (map->player_char == 'E' && map->matrix[map->player_y][map->player_x - 1] != '1')
		data->map.player_x--;
	else if (map->player_char == 'W' && map->matrix[map->player_y][map->player_x + 1] != '1')
		data->map.player_x++;
}

static void	move_left(t_data *data)
{
	t_map *map;

	map = &data->map;
	if (map->player_char == 'N' && map->matrix[map->player_y][map->player_x - 1] != '1')
		data->map.player_x--;
	else if (map->player_char == 'S' && map->matrix[map->player_y][map->player_x + 1] != '1')
		data->map.player_x++;
	else if (map->player_char == 'E' && map->matrix[map->player_y - 1][map->player_x] != '1')
		data->map.player_y--;
	else if (map->player_char == 'W' && map->matrix[map->player_y + 1][map->player_x] != '1')
		data->map.player_y++;
}

static void	move_right(t_data *data)
{
	t_map *map;

	map = &data->map;
	if (map->player_char == 'N' && map->matrix[map->player_y][map->player_x + 1] != '1')
		data->map.player_x++;
	else if (map->player_char == 'S' && map->matrix[map->player_y][map->player_x - 1] != '1')
		data->map.player_x--;
	else if (map->player_char == 'E' && map->matrix[map->player_y + 1][map->player_x] != '1')
		data->map.player_y++;
	else if (map->player_char == 'W' && map->matrix[map->player_y - 1][map->player_x] != '1')
		data->map.player_y--;
}

static void	turn_left(t_data *data)
{
	t_map *map;

	map =&data->map;
	if (map->player_char == 'N')
		map->player_char = 'W';
	else if (map->player_char == 'S')
		map->player_char = 'E';
	else if (map->player_char == 'E')
		map->player_char = 'N';
	else if (map->player_char == 'W')
		map->player_char = 'S';
}

static void	turn_right(t_data *data)
{
	t_map *map;

	map =&data->map;
	if (map->player_char == 'N')
		map->player_char = 'E';
	else if (map->player_char == 'S')
		map->player_char = 'W';
	else if (map->player_char == 'E')
		map->player_char = 'S';
	else if (map->player_char == 'W')
		map->player_char = 'N';
}
