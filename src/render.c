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
static void	draw_player(t_data *data, int tile_size);

void	render(t_data *data)
{
	render_map2D(data);
}

static void	render_map2D(t_data *data)
{
	int		tile_size;
	int		i;
	int		j;

	if (data->grph.img.img != NULL)
		mlx_destroy_image(data->grph.mlx, data->grph.img.img);
	data->grph.img.img = mlx_new_image(data->grph.mlx, data->grph.window_width,
			data->grph.window_height);
	data->grph.img.addr = mlx_get_data_addr(data->grph.img.img,
			&data->grph.img.bpp, &data->grph.img.line_l,
			&data->grph.img.endian);
	tile_size = 6;
	print_values(data);
	i = 0;
	while (i < tile_size * (int)data->map.rows)
	{
		j = 0;
		while (j < tile_size * (int)data->map.cols)
		{
			if ((j / tile_size) < (int)ft_strlen(data->map.matrix[i
					/ tile_size]) && data->map.matrix[i
				/ tile_size][j / tile_size] == '1')
				put_pixel(&data->grph.img, j, i, 0xFFFFFF);
			else
				put_pixel(&data->grph.img, j, i, 0x000000);
			j++;
		}
		i++;
	}
	draw_player(data, tile_size);
	mlx_put_image_to_window(data->grph.mlx, data->grph.win, data->grph.img.img,
		0, 0);
}

static int	put_pixel(t_img *img, int x, int y, uint32_t color)
{
	char	*px;

	px = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(uint32_t *)px = color;
	return (0);
}

static void	draw_player(t_data *data, int tile_size)
{
	t_dir dir;
	int x;
	int y;
	int player_size;

	dir.p_x = data->grph.dir.p_x * tile_size;
	dir.p_y = data->grph.dir.p_y * tile_size;
	player_size = 3;
	y = (int)dir.p_y - player_size;
	while (y <= (int)dir.p_y + player_size)
	{
		x = (int)dir.p_x - player_size;
		while (x <= (int)dir.p_x + player_size)
		{
			if ((x - dir.p_x) * (x - dir.p_x) + (y - dir.p_y) * (y
					- dir.p_y) <= player_size * player_size)
				put_pixel(&data->grph.img, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}