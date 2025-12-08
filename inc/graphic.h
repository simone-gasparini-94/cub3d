/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:30:54 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/08 18:37:41 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

# define PI 3.14159265359
# define CONSTANT 5
# define INCREMENT 0.25
# define MOVEMENT 0.25

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
	double	x_d;
	double	y_d;
	double	pa;
	double	p_x;
	double	p_y;
}			t_dir;

typedef struct s_grph
{
	t_img	img;
	t_dir	dir;
	void	*mlx;
	void	*win;
	int		window_width;
	int		window_height;
	int		texture_width;
	int		texture_height;
	int		tile_size;
	int		map_width;
	int		map_height;
	int		padding;
}			t_grph;

int			init_mlx(t_data *data);
void		render(t_data *data);

#endif
