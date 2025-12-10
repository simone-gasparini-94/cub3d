/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:06:35 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 13:18:14 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdbool.h>
# include <sys/types.h>

typedef struct s_node
{
	char			*s;
	struct s_node	*next;
}					t_node;

typedef struct s_map
{
	char			**matrix; //map parsed from file
	char			**map; //map modified with areas and doors
	size_t			rows;
	size_t			cols;
	bool			parsed;
	char			player_char;
	size_t			player_x;
	size_t			player_y;
	ssize_t			empty_spaces;
}					t_map;

bool				is_map(t_data *data, char *s);
int					parse_map(t_data *data, char *s, int fd);
bool				map_check(t_data *data);
void  				set_doors(t_data    *data);
void				fill_area(char  **map, char c, size_t y, size_t x, t_data *data);
void				find_enclosed_areas(t_data *data, char *area_char);
void				find_next_area(char **map, size_t *y, size_t *x, char c);
void				find_eligible_walls(t_map *map);

#endif
