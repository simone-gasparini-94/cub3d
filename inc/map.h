#ifndef MAP_H
# define MAP_H

#include <stdbool.h>

typedef struct s_map
{
    char    **m;
    size_t  rows;
    size_t  x;
    size_t  y;
}   t_map;

#endif