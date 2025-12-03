/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 16:48:28 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/03 16:52:32 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <sys/types.h>
#include <stdio.h>

void	print_values(t_data *data)
{
	size_t	i;

	printf("\n");
	i = 0;
	while (i < data->map.rows)
		printf("%s\n", data->map.matrix[i++]);
	printf("\n");
	printf("%s:\t%d, %d, %d\n",
			data->rgb[F].id, data->rgb[F].red,
			data->rgb[F].green, data->rgb[F].blue);
	printf("%s:\t%d, %d, %d\n",
			data->rgb[C].id, data->rgb[C].red,
			data->rgb[C].green, data->rgb[C].blue);
	printf("\n");
	printf("%s:\t%s\n", data->tex[NO].id, data->tex[NO].path);
	printf("%s:\t%s\n", data->tex[SO].id, data->tex[SO].path);
	printf("%s:\t%s\n", data->tex[EA].id, data->tex[EA].path);
	printf("%s:\t%s\n", data->tex[WE].id, data->tex[WE].path);
	printf("\n");
}
