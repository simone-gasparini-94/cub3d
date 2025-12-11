/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:13:44 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/11 12:34:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "libft.h"
#include "parse.h"
#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static void	render_map2D(t_grph *grph, t_data *data);
static void	render_3D(t_grph *grph, t_data *data);
static void	draw_player(t_grph *grph);
static double cast_ray(t_grph *grph, t_data *data, double ray_angle);

void	render(t_data *data)
{
	render_3D(&data->grph, data);
	render_map2D(&data->grph, data);
	mlx_put_image_to_window(data->grph.mlx, data->grph.win, data->grph.img.img,
			0, 0);
}

static void	render_3D(t_grph *grph, t_data *data)
{
	double	*distances;
	int		i;
	int		y;
	int		num_rays;
	double	ray_angle;
	double	angle_step;
	int		wall_height;
	int		wall_top;
	int		wall_bottom;

	if (grph->img.img != NULL)
		mlx_destroy_image(grph->mlx, grph->img.img);
	grph->img.img = mlx_new_image(grph->mlx, grph->window_width,
			grph->window_height);
	grph->img.addr = mlx_get_data_addr(grph->img.img,
			&grph->img.bpp, &grph->img.line_l,
			&grph->img.endian);
	num_rays = grph->window_width;
	distances = malloc(sizeof(double) * num_rays);
	angle_step = (60.0 * PI / 180.0) / num_rays;
	ray_angle = grph->dir.angle - (30.0 * PI / 180.0);
	i = 0;
	while (i < num_rays)
	{
		ray_angle = grph->dir.angle - (30.0 * PI / 180.0) + (angle_step * i);
		distances[i] = cast_ray(grph, data, ray_angle);
		wall_height = (grph->window_height / distances[i]);
		wall_top = (grph->window_height / 2) - (wall_height / 2);
		wall_bottom = (grph->window_height / 2) + (wall_height / 2);
		if (wall_top < 0)
			wall_top = 0;
		if (wall_bottom > grph->window_height)
			wall_bottom = grph->window_height - 1;
		y = wall_top;
		while (y < wall_bottom)
		{
			put_pixel(&grph->img, i, y, 0x8E8E8E, grph);
			y++;
		}
		i++;
	}
}

static double cast_ray(t_grph *grph, t_data *data, double ray_angle)
{
	double	distance;
	double	step;
	double	x;
	double	y;

	distance = 0;
	step = 0.01;
	x = grph->pl.x;
	y = grph->pl.y;
	while (distance < 1000)
	{
		if (data->map.map[(int)y][(int)x] == '1'
				|| data->map.map[(int)y][(int)x] == '\\')
			break ;
		x += cos(ray_angle) * step;
		y += sin(ray_angle) * step;
		distance += step;
	}
	return (distance);
}

static void	render_map2D(t_grph *grph, t_data *data)
{
	int		i;
	int		j;

	i = 0;
	while (i < grph->map_height) 
	{
		j = 0;
		while (j < grph->map_width)
		{
			if ((j / grph->tile_size) < (int)data->map.cols && data->map.map[i
				/ grph->tile_size][j / grph->tile_size] == '1')
				put_pixel(&grph->img, j, i, 0xFFFFFF, grph);
			else if ((j / grph->tile_size) < (int)data->map.cols 
			&& data->map.map[i / grph->tile_size][j / grph->tile_size] == '\\')
				put_pixel(&grph->img, j, i, 0x8F008F, grph);
			j++;
		}
		i++;
	}
	draw_player(grph);
	draw_rays(grph, data);
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
				put_pixel(&grph->img, x, y, 0xFF0000, grph);
			x++;
		}
		y++;
	}
}

