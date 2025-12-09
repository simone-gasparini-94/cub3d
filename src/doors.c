#include "data.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void find_next_area(char **map, size_t *y, size_t *x);
static void fill_area(char  **map, char c, size_t y, size_t x, t_data *data);
static void	find_vertical_walls(t_data *data);
static void	find_horizontal_walls(t_data *data);

void    set_doors(t_data *data)
{
    char    area_char;
    size_t  y;
    size_t  x;

    data->map.map = copy_matrix(data);
    area_char = 'a';
    y = 1;
    x = 1;
    while (data->map.empty_spaces > 0 && area_char < 'z')
    {
        find_next_area(data->map.map, &y, &x);
        fill_area(data->map.map, area_char, y, x, data);
        area_char++;
    }
	find_vertical_walls(data);
	find_horizontal_walls(data);
}

static void find_next_area(char **map, size_t *y, size_t *x)
{
    while (map[*y] != NULL)
    {
        *x = 1;
        while (map[*y][*x])
        {
            if (map[*y][*x] == '0')
                return ;
            (*x)++;
        }   
        (*y)++;
    }
}

static void fill_area(char  **map, char c, size_t y, size_t x, t_data *data)
{
    if (map[y][x] == '1' || map[y][x] == c)
        return ;
    if (ft_isalpha(map[y][x]) == true && map[y][x] < c)
        return ;
    map[y][x] = c;
    data->map.empty_spaces--;
    fill_area(map, c, y + 1, x, data);
    fill_area(map, c, y, x + 1, data);
    fill_area(map, c, y - 1, x, data);
    fill_area(map, c, y, x - 1, data);
}

static void	find_vertical_walls(t_data *data)
{
	char	**map;
	size_t	x;
	size_t	y;

	map = data->map.map;
	y = 1;
	while (y < data->map.rows - 1)
	{
		x = 1;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == '1' && ft_isalpha(map[y][x - 1])
				&& ft_isalpha(map[y][x + 1])
				&& map[y][x - 1] != map[y][x + 1])
					map[y][x] = '~';
			x++;
		}
		y++;
	}
}

static void	find_horizontal_walls(t_data *data)
{
	(void)data;
}
