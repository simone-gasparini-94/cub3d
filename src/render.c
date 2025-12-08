/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:13:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/08 18:41:58 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include "parse.h"
#include <mlx.h>
#include <stdio.h>

static void	render_map2D(t_grph *grph, t_data *data);
static int	put_pixel(t_img *img, int x, int y, uint32_t color);
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
			if ((j / grph->tile_size) < (int)ft_strlen(data->map.matrix[i
					/ grph->tile_size]) && data->map.matrix[i
				/ grph->tile_size][j / grph->tile_size] == '1')
				put_pixel(&grph->img, j, i, 0xFFFFFF);
			j++;
		}
		i++;
	}
	draw_player(grph);
	mlx_put_image_to_window(grph->mlx, grph->win, grph->img.img,
		grph->window_width - grph->map_width - grph->padding,
		grph->window_height - grph->map_height - grph->padding);
}

static int	put_pixel(t_img *img, int x, int y, uint32_t color)
{
	char	*px;

	px = img->addr + (y * img->line_l + x * (img->bpp / 8));
	*(uint32_t *)px = color;
	return (0);
}

static void	draw_player(t_grph *grph)
{
	t_dir dir;
	int x;
	int y;
	int player_size;

	dir.p_x = grph->dir.p_x * grph->tile_size;
	dir.p_y = grph->dir.p_y * grph->tile_size;
	player_size = 3;
	y = (int)dir.p_y - player_size;
	while (y <= (int)dir.p_y + player_size)
	{
		x = (int)dir.p_x - player_size;
		while (x <= (int)dir.p_x + player_size)
		{
			if ((x - dir.p_x) * (x - dir.p_x) + (y - dir.p_y) * (y
					- dir.p_y) <= player_size * player_size)
				put_pixel(&grph->img, x, y, 0xFF0000);
			x++;
		}
		y++;
	}
}
