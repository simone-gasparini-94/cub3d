/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:13:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 16:33:40 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include "parse.h"
#include <mlx.h>
#include <stdio.h>
#include <math.h>

static void	render_map2D(t_grph *grph, t_data *data);
static void	draw_player(t_grph *grph);

void	render(t_data *data)
{
	render_map2D(&data->grph, data);
}

static void	render_map2D(t_grph *grph, t_data *data)
{
	int		i;
	int		j;

	if (grph->img.img != NULL)
		mlx_destroy_image(grph->mlx, grph->img.img);
	grph->img.img = mlx_new_image(grph->mlx, grph->window_width,
			grph->window_height);
	grph->img.addr = mlx_get_data_addr(grph->img.img,
			&grph->img.bpp, &grph->img.line_l,
			&grph->img.endian);
	i = 0;
	while (i < grph->map_height) 
	{
		j = 0;
		while (j < grph->map_width)
		{
			if ((j / grph->tile_size) < (int)data->map.cols && data->map.map[i
				/ grph->tile_size][j / grph->tile_size] == '1')
				put_pixel(&grph->img, j, i, 0xFFFFFF);
			else if ((j / grph->tile_size) < (int)data->map.cols 
			&& data->map.map[i / grph->tile_size][j / grph->tile_size] == '\\')
				put_pixel(&grph->img, j, i, 0x8F008F);
			j++;
		}
		i++;
	}
	draw_player(grph);
	draw_rays(grph, data);
	mlx_put_image_to_window(grph->mlx, grph->win, grph->img.img,
		grph->window_width - grph->map_width - grph->padding,
		grph->window_height - grph->map_height - grph->padding);
}

int	put_pixel(t_img *img, int x, int y, uint32_t color)
{
	char	*px;

	px = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(uint32_t *)px = color;
	return (0);
}

static void	draw_player(t_grph *grph)
{
	t_pl pl;
	int x;
	int y;
	int player_size;

	pl.x = grph->pl.x * grph->tile_size;
	pl.y = grph->pl.y * grph->tile_size;
	player_size = grph->tile_size / 3;
	y = (int)pl.y - player_size;
	while (y <= (int)pl.y + player_size)
	{
		x = (int)pl.x - player_size;
		while (x <= (int)pl.x + player_size)
		{
			if ((x - pl.x) * (x - pl.x) + (y - pl.y) * (y
					- pl.y) <= player_size * player_size)
				put_pixel(&grph->img, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}

