/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   areas.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:28:03 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 11:33:10 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "utils.h"
#include "libft.h"
#include "print.h"
#include <stdlib.h>
#include <stdio.h>

static void fill_area(char  **map, char c, size_t y, size_t x, t_data *data);

void	find_enclosed_areas(t_data *data, char *area_char)
{
	size_t	y;
	size_t	x;

	y = 1;
	x = 1;
    while (data->map.empty_spaces > 0 && *area_char < 'z')
    {
        find_next_area(data->map.map, &y, &x, '0');
        fill_area(data->map.map, *area_char, y, x, data);
        (*area_char)++;
    }
}

void	find_next_area(char **map, size_t *y, size_t *x, char c)
{
    while (map[*y] != NULL)
    {
        *x = 1;
        while (map[*y][*x])
        {
            if (map[*y][*x] == c)
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
