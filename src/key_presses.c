/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:45:27 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/09 10:51:54 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "destroy.h"
#include "graphic.h"
#include <X11/keysym.h>
#include <math.h>
#include <mlx.h>
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

static void	move_backwards(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->grph.pl.x + cos(data->grph.dir.angle) * MOVEMENT);
	y = (int)(data->grph.pl.y + sin(data->grph.dir.angle) * MOVEMENT);
	printf("x: %d\n", x);
	if (data->map.matrix[y][x] != '1')
	{
		data->grph.pl.x += cos(data->grph.dir.angle) * MOVEMENT;
		data->grph.pl.y += sin(data->grph.dir.angle) * MOVEMENT;
	}
}

static void	move_forward(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->grph.pl.x - cos(data->grph.dir.angle) * MOVEMENT);
	y = (int)(data->grph.pl.y - sin(data->grph.dir.angle) * MOVEMENT);
	if (data->map.matrix[y][x] != '1')
	{
		data->grph.pl.x -= cos(data->grph.dir.angle) * MOVEMENT;
		data->grph.pl.y -= sin(data->grph.dir.angle) * MOVEMENT;
	}
}

static void	move_left(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->grph.pl.x - cos(data->grph.dir.angle - PI / 2) * MOVEMENT);
	y = (int)(data->grph.pl.y - sin(data->grph.dir.angle - PI / 2) * MOVEMENT);
	if (data->map.matrix[y][x] != '1')
	{
		data->grph.pl.x -= cos(data->grph.dir.angle - PI / 2) * MOVEMENT;
		data->grph.pl.y -= sin(data->grph.dir.angle - PI / 2) * MOVEMENT;
	}
}

static void	move_right(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->grph.pl.x - cos(data->grph.dir.angle + PI / 2) * MOVEMENT);
	y = (int)(data->grph.pl.y - sin(data->grph.dir.angle + PI / 2) * MOVEMENT);
	if (data->map.matrix[y][x] != '1')
	{
		data->grph.pl.x -= cos(data->grph.dir.angle + PI / 2) * MOVEMENT;
		data->grph.pl.y -= sin(data->grph.dir.angle + PI / 2) * MOVEMENT;
	}
}

static void	turn_right(t_data *data)
{
	data->grph.dir.angle += INCREMENT * PI;
	if (data->grph.dir.angle >= (2 * PI))
		data->grph.dir.angle -= (2 * PI);
	data->grph.dir.x = cos(data->grph.dir.angle) * CONSTANT;
	data->grph.dir.y = sin(data->grph.dir.angle) * CONSTANT;
}

static void	turn_left(t_data *data)
{
	data->grph.dir.angle -= INCREMENT * PI;
	if (data->grph.dir.angle < (0 * PI))
		data->grph.dir.angle += (2 * PI);
	data->grph.dir.x = cos(data->grph.dir.angle) * CONSTANT;
	data->grph.dir.y = sin(data->grph.dir.angle) * CONSTANT;
}
