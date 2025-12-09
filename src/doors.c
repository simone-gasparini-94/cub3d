#include "data.h"
#include "utils.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

static void find_next_area(char **map, size_t *y, size_t *x);
static void fill_area(char  **map, char c, size_t y, size_t x, t_data *data);
static  void    locate_horizontal_wall(char **map, char c);
static  void    locate_vertical_wall(char **map, char c);

void    set_doors(t_data    *data)
{
    char    **map;
    char    area_char;
    size_t  position_y;
    size_t  position_x;


    map = copy_matrix(data);
    area_char = 'a';
    position_y = 1;
    position_x = 1;
    while (data->map.empty_spaces > 0 && area_char < 'z')
    {
        find_next_area(map, &position_y, &position_x);
        fill_area(map, area_char, position_y, position_x, data);
        area_char++;
    }
    locate_horizontal_wall(map, area_char);
    locate_vertical_wall(map, area_char);
    for (int   i = 0; map[i]; i++)
        printf("%s\n", map[i]);
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

static  void    locate_horizontal_wall(t_data *data, char **map, char c, size_t y)
{
    size_t  y;
    size_t  x;

    y = 1;
    while (y < data->map.rows - 1)
    {
        x = 1;
        while (map[y][x] && map[y][x] != c)
            x++;
        while (map[y][x])
        {
            if (map[y][x] == '1')
            {
                if (map[y][x + 1] == '0' && map[y][x - 1] == c)
                {
                    map[y][x] = ft_toupper(c);
                    break ;
                }
            }
            x++;
        }
        y++;
    }
}

/* 
static void locate_vertical_wall(char **map, char c, size_t x)
{
    size_t y = 1;

    while (map[y] && map[y][x])
    {
        while (map[y][x] && map[y][x] != c)
            y++;

        if (!map[y][x])
            break;
        while (map[y][x])
        {
            if (map[y][x] == '1')
            {
                if (map[y + 1] && map[y + 1][x] == '0' &&
                    y > 0 && map[y - 1][x] != '1')
                {
                    map[y][x] = ft_toupper(c);
                    break;
                }
            }
            else if (map[y][x] != c && !ft_isspace(map[y][x]))
            {
                y++;
                continue;
            }
            y++;
        }
        y++;
    }
} */


