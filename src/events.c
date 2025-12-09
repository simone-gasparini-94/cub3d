/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:45:27 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/09 11:10:48 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "events.h"
#include <mlx.h>
#include <X11/keysym.h>

int	handle_events(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit(data);
	if (keysym == XK_W || keysym == XK_w
			|| keysym == XK_S || keysym == XK_s
			|| keysym == XK_A || keysym == XK_a
			|| keysym == XK_D || keysym == XK_d)
		move(keysym, data);
	if (keysym == XK_Left || keysym == XK_Right)
		turn(keysym, data);
	return (0);
}

int	quit(t_data *data)
{
	mlx_loop_end(data->grph.mlx);
	return (0);
}
