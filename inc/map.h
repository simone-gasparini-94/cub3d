/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:06:35 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 13:44:41 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <sys/types.h>
#include <stdbool.h>

typedef struct s_node
{
	char	*s;
	struct s_node *next;
}	t_node;

typedef struct s_map
{
    char	**matrix;
	size_t	rows;
	bool	parsed;
}   t_map;

bool	is_map(t_data *data, char *s);
int		parse_map(t_data *data, char *s, int fd);

#endif
