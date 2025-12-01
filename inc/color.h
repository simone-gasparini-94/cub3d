/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:50:29 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/01 18:24:35 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include <stdint.h>
# include <stdbool.h>

typedef struct s_data t_data;

typedef enum s_sur
{
	C,
	F
}	t_sur;

typedef struct s_rgb
{
	char	*id;
	uint8_t	red;
	uint8_t	green;
	uint8_t	blue;
	bool	parsed;
}			t_rgb;

bool	is_color(t_data *data, char *s);
void	parse_color(t_data *data, char *s);

#endif
