/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:10:50 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/01 18:48:18 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "data.h"
#include "libft.h"
#include <stdio.h>
#include <stdbool.h>

bool	is_color(t_data *data, char *s)
{
	if (ft_strncmp("C ", s, 2) == 0 && data->rgb[C].parsed == false)
		return (true);
	else if (ft_strncmp("F ", s, 2) == 0 && data->rgb[F].parsed == false)
		return (true);
	else
		return (false);
}

void	parse_color(t_data *data, char *s)
{
	char	**arr;
	char	**colors;

	// F 255,0,0
	arr = ft_split(s, ' ');
	// trim
	colors = ft_split(arr[1], ',');
	if (ft_strncmp("C", arr[0], 2) == 0)
	{
		data->rgb[C].id = arr[0];
		data->rgb[C].red = ft_atoi(colors[0]);
		data->rgb[C].green = ft_atoi(colors[1]);
		data->rgb[C].blue = ft_atoi(colors[2]);
		data->rgb[C].parsed = true;
	}
	else if (ft_strncmp("F", arr[0], 2) == 0)
	{
		data->rgb[F].id = arr[0];
		data->rgb[F].red = ft_atoi(colors[0]);
		data->rgb[F].green = ft_atoi(colors[1]);
		data->rgb[F].blue = ft_atoi(colors[2]);
		data->rgb[F].parsed = true;
	}
}
