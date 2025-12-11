/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:30:54 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/11 12:51:20 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# define PI 3.14159265359
# define MOVEMENT 0.25
# define CENTRE 0.5

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_dir
{
	double	angle;
	double	x;
	double	y;
}			t_dir;

typedef struct s_pl
{
	double	x;
	double	y;
	double	x_grph;
	double	y_grph;
}	t_pl;

typedef struct s_grph
{
	t_img	img;
	t_dir	dir;
	t_pl	pl;
	void	*mlx;
	void	*win;
	int		window_width;
	int		window_height;
	int		texture_width;
	int		texture_height;
	int		tile_size;
	int		map_width;
	int		map_height;
	int		map_x;
	int		map_y;
	int		padding;
}			t_grph;

int			init_mlx(t_data *data);
void		render(t_data *data);
void		draw_rays(t_grph *grph, t_data *data);
int			put_pixel(t_img *img, int x, int y, uint32_t color, t_grph *grph);

#endif
