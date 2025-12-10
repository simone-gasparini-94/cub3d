/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:54:16 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 14:44:42 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "graphic.h"
#include <X11/keysym.h>
#include <math.h>
#include <mlx.h>

static void	turn_left(t_data *data);
static void	turn_right(t_data *data);

void	turn(int keysym, t_data *data)
{
	if (keysym == XK_Left)
		turn_left(data);
	if (keysym == XK_Right)
		turn_right(data);
	render(data);
}
	
static void	turn_right(t_data *data)
{
	data->grph.dir.angle += PI / 6;
	if (data->grph.dir.angle >= (2 * PI))
		data->grph.dir.angle -= (2 * PI);
	data->grph.dir.x = cos(data->grph.dir.angle);
	data->grph.dir.y = sin(data->grph.dir.angle);
}

static void	turn_left(t_data *data)
{
	data->grph.dir.angle -= PI / 6;
	if (data->grph.dir.angle < (0 * PI))
		data->grph.dir.angle += (2 * PI);
	data->grph.dir.x = cos(data->grph.dir.angle);
	data->grph.dir.y = sin(data->grph.dir.angle);
}
