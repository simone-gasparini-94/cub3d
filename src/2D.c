#include "data.h"
#include <math.h>
#include <stdio.h>

static void draw_single_ray(t_grph *grph, t_data *data, double ray_angle);
static void	draw_rays(t_grph *grph, t_data *data);

void	render_map2D(t_grph *grph, t_data *data)
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
				put_pixel(&grph->img, grph->map_x + j, grph->map_y + i, 0xFFFFFF, grph);
			else if ((j / grph->tile_size) < (int)data->map.cols 
			&& data->map.map[i / grph->tile_size][j / grph->tile_size] == '\\')
				put_pixel(&grph->img, grph->map_x + j, grph->map_y + i, 0x8E008E, grph);
			j++;
		}
		i++;
	}
	draw_rays(grph, data);
}

static void	draw_rays(t_grph *grph, t_data *data)
{
	int		i;
	int		num_rays;
	double	ray_angle;
	double	angle_step;

	num_rays = 60;
	angle_step = PI / 180.0;
	ray_angle = grph->dir.angle - (30.0 * PI / 180.0);
	i = 0;
	while (i < num_rays)
	{
		ray_angle += angle_step;
		draw_single_ray(grph, data, ray_angle);
		i++;
	}
}
static void draw_single_ray(t_grph *grph, t_data *data, double ray_angle)
{
    int     ray_size;
    int		i;
	int		x;
	int		y;

    i = 0;
    ray_size = 46;
    while (i < ray_size)
    {
        x = grph->pl.x_grph + cos(ray_angle) * i;
        y = grph->pl.y_grph + sin(ray_angle) * i;
        
        if (x >= 0 && x < grph->map_width && y >= 0 && grph->map_height
                && data->map.map[y / grph->tile_size][x / grph->tile_size] != '1'
                && data->map.map[y / grph->tile_size][x / grph->tile_size] != '\\')
            put_pixel(&grph->img, grph->map_x + x, grph->map_y + y, 0x00FF00, grph);
        else
            break;
        i++;
    }
}
