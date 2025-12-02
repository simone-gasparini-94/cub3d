/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:10:50 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 14:46:01 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "data.h"
#include "destroy.h"
#include "libft.h"
#include <stdio.h>
#include <stdbool.h>

static void	fill_rgb_elements(t_data *data, char **arr, t_sur sur);

bool	is_color(t_data *data, char *s)
{
	if (ft_strncmp("C ", s, 2) == 0 && data->rgb[C].parsed == false)
		return (true);
	else if (ft_strncmp("F ", s, 2) == 0 && data->rgb[F].parsed == false)
		return (true);
	else
		return (false);
}

int	parse_color(t_data *data, char *s)
{
	char	**arr;

	arr = ft_split(s, ' ');
	if (arr[0] == NULL || arr[1] == NULL || arr[2] != NULL)
		return (1);
	if (ft_strncmp("C", arr[0], 2) == 0)
		fill_rgb_elements(data, arr, C);
	else if (ft_strncmp("F", arr[0], 2) == 0)
		fill_rgb_elements(data, arr, F);
	if (data->rgb[C].parsed == true
			&& data->tex[F].parsed == true)
		data->rgb_parsed = true;
	destroy_array_str(arr);
	return (0);
}

static void	fill_rgb_elements(t_data *data, char **arr, t_sur sur)
{
	char	**colors;

	colors = ft_split(arr[1], ',');
	data->rgb[sur].id = arr[0];
	data->rgb[sur].red = ft_atoi(colors[0]);
	data->rgb[sur].green = ft_atoi(colors[1]);
	data->rgb[sur].blue = ft_atoi(colors[2]);
	data->rgb[sur].parsed = true;
	destroy_array_str(colors);
}
