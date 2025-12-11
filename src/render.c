/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:13:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/11 12:55:04 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include "parse.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void	render(t_data *data)
{
	if (data->grph.img.img != NULL)
		mlx_destroy_image(data->grph.mlx, data->grph.img.img);
	data->grph.img.img = mlx_new_image(data->grph.mlx, data->grph.window_width,
			data->grph.window_height);
	data->grph.img.addr = mlx_get_data_addr(data->grph.img.img,
			&data->grph.img.bpp, &data->grph.img.line_l,
			&data->grph.img.endian);
	render_3D(&data->grph, data);
	render_map2D(&data->grph, data);
	mlx_put_image_to_window(data->grph.mlx, data->grph.win, data->grph.img.img,
			0, 0);
}

int	put_pixel(t_img *img, int x, int y, uint32_t color, t_grph *grph)
{
	char	*px;

	if (x < 0 || x >= grph->window_width || y < 0 || y >= grph->window_height)
		return (1);
	px = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(uint32_t *)px = color;
	return (0);
}
