/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:40:01 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 09:51:03 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "color.h"
# include "grafic.h"
# include "map.h"
# include "texture.h"

typedef struct s_data
{
	t_map	map;
	t_tex	tex[4];
	t_rgb	rgb[2];
	t_mlx	grph[1];
	bool	tex_parsed;
	bool	rgb_parsed;
}			t_data;

t_data		*create_data(void);

#endif
