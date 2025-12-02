/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 11:39:31 by duccello          #+#    #+#             */
/*   Updated: 2025/12/01 11:52:47 by duccello         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdbool.h>
#include <sys/types.h>
#include "map.h"

bool	wall_check(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->m[i][j] != '\0')
		{
			if (map->m[i][j] == 0)
			{
				if (map->m[i][j - 1] != '0' || map->m[i][j - 1] != '1'
					|| map->m[i][j - 1] != 'N')
					return (false);
				if (map->m[i - 1][j] != '0' || map->m[i - 1][j] != '1' || map->m[i
					- 1][j] != 'N')
					return (false);
				if (map->m[i][j + 1] != '0' || map->m[i][j + 1] != '1'
					|| map->m[i][j + 1] != 'N')
					return (false);
				if (map->m[i + 1][j] != '0' || map->m[i + 1][j] != '1' || map->m[i
					+ 1][j] != 'N')
					return (false);
			}
			j++;
		}
		i++;
	}
	return (true);
}

bool	player_check(t_map *map)
{
	size_t	i;
	size_t	j;
	size_t	p;

	i = 0;
	p = 0;
	while (i < map->rows)
	{
		j = 0;
		while (map->m[i][j] != '\0')
		{
			if (map->m[i][j] == 'N')
			{
				p++;
				map->x = i;
				map->y = j;	
			}
			j++;
		}
		i++;
	}
	if (p != 1)
		return (false);
	return (true);
}