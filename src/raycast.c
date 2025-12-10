#include "data.h"
#include <math.h>
#include <stdio.h>

static void draw_single_ray(t_grph *grph, t_data *data, double ray_angle);

void	draw_rays(t_grph *grph, t_data *data)
{
	int		i;
	int		num_rays;
	double	ray_angle;
	double	angle_step;

	num_rays = 60;
	angle_step = PI / 180.0;
	i = 0;
	while (i < num_rays)
	{
		ray_angle = grph->dir.angle - (30.0 * PI / 180.0) + (angle_step * i);
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
                && data->map.matrix[y / grph->tile_size][x / grph->tile_size] != '1')
            put_pixel(&grph->img, x, y, 0x00FF00); // Green rays
        else
            break;
        i++;
    }
}