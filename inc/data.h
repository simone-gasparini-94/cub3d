/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 16:40:01 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 10:21:10 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_H
# define DATA_H

# include "texture.h"
# include "color.h"
# include "map.h"

typedef struct s_data
{
	t_map				map;
	t_tex				tex[4];
	t_rgb				rgb[2];
	bool				map_parsed;
	bool				tex_parsed;
	bool				rgb_parsed;
}						t_data;

t_data	*create_data(void);

#endif
