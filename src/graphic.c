/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 10:14:15 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/11 16:10:20 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "destroy.h"
#include "ft_fprintf.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>

static int	init_mlx_images(t_data *data);
static void	init_graphic_values(t_data *data, t_grph *grph);
static void	set_player_angle(t_data *data);

int	init_mlx(t_data *data)
{
	init_graphic_values(data, &data->grph);
	set_player_angle(data);
	data->grph.mlx = mlx_init();
	if (data->grph.mlx == NULL)
	{
		ft_fprintf(STDERR_FILENO, "Error\nMLX Initialization Failed\n");
		return (1);
	}
	data->grph.win = mlx_new_window(data->grph.mlx, data->grph.window_width,
			data->grph.window_height, "Test_numero_1");
	if (data->grph.win == NULL)
	{
		ft_fprintf(STDERR_FILENO, "Error\nMLX New Window Failed\n");
		return (1);
	}
	if (init_mlx_images(data) == 1)
	{
		ft_fprintf(STDERR_FILENO, "Error\nInvalid Path to Texture\n");
		return (1);
	}

	return (0);
}

static void	init_graphic_values(t_data *data, t_grph *grph)
{
	grph->texture_width = 256;
	grph->texture_height = 256;
	grph->window_width = 1080;
	grph->window_height = 720;
	grph->tile_size = 4;
	grph->mini.width = data->map.cols * grph->tile_size;
	grph->mini.height = data->map.rows * grph->tile_size;
	grph->mini.padding = grph->window_height / 16;
	grph->mini.x = grph->window_width - grph->mini.width - grph->mini.padding;
	grph->mini.y = grph->window_height - grph->mini.height - grph->mini.padding;
	grph->multi = 1.0;
}

int	init_mlx_images(t_data *data)
{
	data->tex[NO].texture = mlx_xpm_file_to_image(data->grph.mlx,
			data->tex[NO].path, &data->grph.texture_width,
			&data->grph.texture_height);
	data->tex[SO].texture = mlx_xpm_file_to_image(data->grph.mlx,
			data->tex[SO].path, &data->grph.texture_width,
			&data->grph.texture_height);
	data->tex[EA].texture = mlx_xpm_file_to_image(data->grph.mlx,
			data->tex[EA].path, &data->grph.texture_width,
			&data->grph.texture_height);
	data->tex[WE].texture = mlx_xpm_file_to_image(data->grph.mlx,
			data->tex[WE].path, &data->grph.texture_width,
			&data->grph.texture_height);
	if (data->tex[NO].texture == NULL || data->tex[SO].texture == NULL
		|| data->tex[WE].texture == NULL || data->tex[EA].texture == NULL)
		return (1);
	return (0);
}

static void	set_player_angle(t_data *data)
{
	t_map *map;

	map = &data->map;
	if (map->player_char == 'N')
		data->grph.dir.angle = PI / 2;
	else if (map->player_char == 'S')
		data->grph.dir.angle = PI * 3 / 2;
	else if (map->player_char == 'E')
		data->grph.dir.angle = 0;
	else if (map->player_char == 'W')
		data->grph.dir.angle = PI;
	data->grph.pl.x = (double)data->map.player_x + CENTRE;
	data->grph.pl.y = (double)data->map.player_y + CENTRE;
	data->grph.pl.x_grph = data->grph.pl.x * data->grph.tile_size;
	data->grph.pl.y_grph = data->grph.pl.y * data->grph.tile_size;
	data->grph.dir.x = cos(data->grph.dir.angle);
	data->grph.dir.y = sin(data->grph.dir.angle);
}
