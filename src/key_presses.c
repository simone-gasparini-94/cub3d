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
#include <math.h>
#include <mlx.h>
#include <stdio.h>

static void	move_forward(t_data *data);
static void	move_backwards(t_data *data);
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
	int	x;
	int	y;

	x = (int)(data->grph.dir.p_x + cos(data->grph.dir.pa) * MOVEMENT);
	y = (int)(data->grph.dir.p_y + sin(data->grph.dir.pa) * MOVEMENT);
	printf("x: %d\n", x);
	if (data->map.matrix[y][x] != '1')
	{
		data->grph.dir.p_x += cos(data->grph.dir.pa) * MOVEMENT;
		data->grph.dir.p_y += sin(data->grph.dir.pa) * MOVEMENT;
	}
}

static void	move_backwards(t_data *data)
{
	int	x;
	int	y;

	x = (int)(data->grph.dir.p_x - cos(data->grph.dir.pa) * MOVEMENT);
	y = (int)(data->grph.dir.p_y - sin(data->grph.dir.pa) * MOVEMENT);
	if (data->map.matrix[y][x] != '1')
	{
		data->grph.dir.p_x -= cos(data->grph.dir.pa) * MOVEMENT;
		data->grph.dir.p_y -= sin(data->grph.dir.pa) * MOVEMENT;
	}
}

static void	turn_right(t_data *data)
{
	data->grph.dir.pa += INCREMENT;
	if (data->grph.dir.pa >= (2 * PI))
		data->grph.dir.pa -= (2 * PI);
	data->grph.dir.x_d = cos(data->grph.dir.pa) * CONSTANT;
	data->grph.dir.y_d = sin(data->grph.dir.pa) * CONSTANT;
}

static void	turn_left(t_data *data)
{
	data->grph.dir.pa -= INCREMENT;
	if (data->grph.dir.pa < (0 * PI))
		data->grph.dir.pa += (2 * PI);
	data->grph.dir.x_d = cos(data->grph.dir.pa) * CONSTANT;
	data->grph.dir.y_d = sin(data->grph.dir.pa) * CONSTANT;
}
