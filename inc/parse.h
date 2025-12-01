#ifndef PARSE_H
#define PARSE_H

#include <stdbool.h>
#include <stdio.h>

int	parse(t_data *data, char *file);
int    parse_textures(t_data *data, char **array, ssize_t len);
bool	wall_check(t_map *map);
bool	player_check(t_map *map);

#endif