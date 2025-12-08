/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:13:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/08 13:26:12 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include "parse.h"
#include <mlx.h>
#include <stdio.h>

static void	render_map2D(t_data *data);
static int	put_pixel(t_img *img, int x, int y, uint32_t color);

void    render(t_data   *data)
{
	render_map2D(data);
}

static void	render_map2D(t_data *data)
{
	double	tile_width;
	double	tile_height;
	int	i;
	int	j;

	data->grph.img.img = mlx_new_image(data->grph.mlx,
			data->grph.window_width, data->grph.window_height);
	data->grph.img.addr = mlx_get_data_addr(data->grph.img.img,
			&data->grph.img.bpp, &data->grph.img.line_l,
			&data->grph.img.endian);
	tile_width = 6;
	tile_height = 6;

	print_values(data);
	i = 0;
	while (i < tile_height * data->map.rows)
	{
		j = 0;
		while (j < tile_width * data->map.cols)
		{
			if ((j / (int)tile_width) < (int)ft_strlen(data->map.matrix[i / (int)tile_height]) 
					&& data->map.matrix[i / (int)tile_height][j / (int)tile_width] == '1')
				put_pixel(&data->grph.img, j, i, 0xFFFFFF);
			else if ((j / (int)tile_width) < (int)ft_strlen(data->map.matrix[i / (int)tile_height])
					&& j /(int)tile_width == (int)data->map.player_x
					&& i / (int)tile_height == (int)data->map.player_y)
				put_pixel(&data->grph.img, j, i, 0xFF0000);
			else
				put_pixel(&data->grph.img, j, i, 0x000000);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(data->grph.mlx, data->grph.win, data->grph.img.img, 0, 0);
}

static int	put_pixel(t_img *img, int x, int y, uint32_t color)
{
	char		*px;

	px = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(uint32_t *)px = color;
	return (0);
}
