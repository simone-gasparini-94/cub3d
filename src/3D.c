#include "data.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static void     init_ray_struct(t_grph *g, t_ray *ray, double angle);
static void     determine_step_size(t_grph *g, t_ray *ray);
static double   cast_ray(t_grph *g, t_data *data, double angle);
static void     draw_3D(t_grph *grph, int ray_n);

void	render_3D(t_grph *grph, t_data *data)
{
	int		i;
	int		num_rays;
	double	ray_angle;
	double	angle_step;

	num_rays = grph->window_width;
	grph->mini.distances = malloc(sizeof(double) * num_rays);
    grph->distances = malloc(sizeof(double) * num_rays);
	angle_step = (60.0 * PI / 180.0) / num_rays;
	ray_angle = grph->dir.angle - (30.0 * PI / 180.0);
	i = 0;
	while (i < num_rays)
	{
		ray_angle = grph->dir.angle - (30.0 * PI / 180.0) + (angle_step * i);
		grph->mini.distances[i] = cast_ray(grph, data, ray_angle);
        grph->distances[i] = grph->mini.distances[i] * cos(ray_angle - grph->dir.angle);
        draw_3D(grph, i);
		i++;
	}
}

static void    draw_3D(t_grph *grph, int ray_n)
{
    int		y;
    int		wall_height;
	int		wall_top;
	int		wall_bottom;

    wall_height = (grph->window_height / grph->distances[ray_n]);
    wall_top = (grph->window_height / 2) - (wall_height / 2);
    wall_bottom = (grph->window_height / 2) + (wall_height / 2);
    if (wall_top < 0)
        wall_top = 0;
    if (wall_bottom > grph->window_height)
        wall_bottom = grph->window_height - 1;
    y = wall_top;
    while (y < wall_bottom)
    {
        put_pixel(&grph->img, ray_n, y, 0x8E8E8E, grph);
        y++;
    }
}

static double    cast_ray(t_grph *g, t_data *data, double angle)
{
    t_ray   ray;

    init_ray_struct(g, &ray, angle);
    while (ray.map_x >= 0 && ray.map_x < g->mini.width &&
       ray.map_y >= 0 && ray.map_y < g->mini.height &&
       data->map.map[ray.map_y][ray.map_x] != '1' &&
       data->map.map[ray.map_y][ray.map_x] != '\\')
    {
        if (ray.side_dist_x < ray.side_dist_y)
        {
            ray.side_dist_x += ray.grid_dist_x;
            ray.map_x += ray.step_x;
            ray.side = VERTICAL;
        }
        else
        {
            ray.side_dist_y += ray.grid_dist_y;
            ray.map_y += ray.step_y;
            ray.side = HORIZONTAL;
        }
    }
    if (ray.side == VERTICAL)
        ray.wall_dist = ray.side_dist_x - ray.grid_dist_x;
    else
        ray.wall_dist = ray.side_dist_y - ray.grid_dist_y;
    return (ray.wall_dist);
}

static void init_ray_struct(t_grph *g, t_ray *ray, double angle)
{
    ray->dir_x = cos(angle);
    ray->dir_y = sin(angle);
    ray->map_x = (int)g->pl.x;
    ray->map_y = (int)g->pl.y;
    ray->grid_dist_x = fabs(1.0 / ray->dir_x);
    ray->grid_dist_y = fabs(1.0 / ray->dir_y);
    determine_step_size(g, ray);
}

static void determine_step_size(t_grph *g, t_ray *ray)
{
    if (ray->dir_x < 0)
    {
        ray->step_x = -1;
        ray->side_dist_x = (g->pl.x - ray->map_x) * ray->grid_dist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->side_dist_x = ((ray->map_x + 1.0) - g->pl.x) * ray->grid_dist_x;
    }

    if (ray->dir_y < 0)
    {
        ray->step_y = -1;
        ray->side_dist_y = (g->pl.y - ray->map_y) * ray->grid_dist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->side_dist_y = ((ray->map_y + 1.0) - g->pl.y) * ray->grid_dist_y  ;
    }
}