#ifndef DATA_H
# define DATA_H

# include "textures.h"
typedef struct s_map	t_map;
typedef struct s_rgb	t_rgb;

typedef struct s_data
{
	t_map				*map;
	t_tex				tex[4];
	t_rgb				*rgb;
}						t_data;

#endif