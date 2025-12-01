#ifndef
# define MAP_H

#include <stdbool.h>

struct s_map
{
    char    **map;
    size_t  rows;
    size_t  x;
    size_t  y;
}   t_map;