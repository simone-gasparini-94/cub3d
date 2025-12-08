/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 10:30:54 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/08 11:03:52 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHIC_H
# define GRAPHIC_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_l;
	int		endian;
}	t_img;

typedef struct s_grph
{
	t_img	img;
	void	*mlx;
	void	*win;
	int		texture_width;
	int		texture_height;
	int		window_width;
	int		window_height;
	double	tile_width;
	double	tile_height;
}			t_grph;

int			init_mlx(t_data *data);
void		render(t_data *data);

#endif
