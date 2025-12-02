/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:06:35 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 11:40:09 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

#include <stdbool.h>

typedef struct s_node
{
	char	*s;
	struct s_node *next;
}	t_node;

typedef struct s_map
{
    t_node	*list;
	bool	parsed;
}   t_map;

bool	is_map(t_data *data, char *s);
int		parse_map(t_data *data, char *s, int fd);

#endif
