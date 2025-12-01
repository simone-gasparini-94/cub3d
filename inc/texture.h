/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:13:57 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/01 17:46:55 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEXTURES_H
# define TEXTURES_H

# include <stdbool.h>

typedef struct s_data t_data;

typedef enum s_card
{
	NO,
	SO,
	EA,
	WE
}	t_card;

typedef struct s_tex
{
    char    *id;
    char    *path;
	bool	parsed;
} 	t_tex;

bool	is_texture(t_data *data, char *s);
void	parse_texture(t_data *data, char *s);

# endif
