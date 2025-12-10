/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:48:28 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 11:43:11 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "print.h"
#include "libft.h"
#include <stdio.h>
#include <sys/types.h>

#define RED     "\033[0;31m"
#define GREEN   "\033[0;32m"
#define YELLOW	"\033[0;33m"
#define RESET   "\033[0m"

void	print_map(t_data *data, t_num n);

void	print_values(t_data *data)
{
	printf("\n");
	printf("%s:\t%d, %d, %d\n", data->rgb[F].id, data->rgb[F].red,
		data->rgb[F].green, data->rgb[F].blue);
	printf("%s:\t%d, %d, %d\n", data->rgb[C].id, data->rgb[C].red,
		data->rgb[C].green, data->rgb[C].blue);
	printf("\n");
	printf("%s:\t%s\n", data->tex[NO].id, data->tex[NO].path);
	printf("%s:\t%s\n", data->tex[SO].id, data->tex[SO].path);
	printf("%s:\t%s\n", data->tex[EA].id, data->tex[EA].path);
	printf("%s:\t%s\n", data->tex[WE].id, data->tex[WE].path);
	printf("\n");
	printf("player_char: %c, player x: %zu, player y: %zu, rows: %zu, cols: %zu\n",
		data->map.player_char, data->map.player_x,
		data->map.player_y, data->map.rows, data->map.cols);
	printf("\n");
	print_map(data, MATRIX);
	printf("\n");
	print_map(data, MAP);
	printf("\n");
}

void	print_map(t_data *data, t_num n)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < data->map.rows)
	{
		j = 0;
		while (j < data->map.cols)
		{
			if (n == MATRIX)
			{
				if (data->map.matrix[i][j] == '1')
					printf(RED "%c" RESET, data->map.matrix[i][j]);
				else
					printf("%c", data->map.matrix[i][j]);
			}
			else
			{
				if (data->map.map[i][j] == '1')
					printf(RED "%c" RESET, data->map.map[i][j]);
				else if (data->map.map[i][j] == '\\')
					printf(GREEN "%c" RESET, data->map.map[i][j]);
				else if (ft_isuppercase(data->map.map[i][j]))
					printf(YELLOW "%c" RESET, data->map.map[i][j]);
				else
					printf("%c", data->map.map[i][j]);
			}
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}
