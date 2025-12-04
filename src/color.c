/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 18:10:50 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/03 16:51:41 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "destroy.h"
#include "libft.h"
#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

static int	fill_rgb_elements(t_data *data, char **arr, t_sur sur);
static bool	are_color_values_valid(char **arr);
static bool	contains_only_digits(char *s);

bool	is_color(t_data *data, char *s)
{
	ft_skip_spaces(&s);
	if (ft_strncmp("C ", s, 2) == 0 && data->rgb[C].parsed == false)
		return (true);
	else if (ft_strncmp("F ", s, 2) == 0 && data->rgb[F].parsed == false)
		return (true);
	else
		return (false);
}

int	parse_color(t_data *data, char *s)
{
	int		ret;
	char	**arr;

	arr = ft_split_once(s, ' ');
	ret = 1;
	if (ft_strncmp("C", arr[0], 2) == 0)
		ret = fill_rgb_elements(data, arr, C);
	else if (ft_strncmp("F", arr[0], 2) == 0)
		ret = fill_rgb_elements(data, arr, F);
	if (data->rgb[C].parsed == true && data->tex[F].parsed == true)
		data->rgb_parsed = true;
	destroy_array_str(arr);
	return (ret);
}

static int	fill_rgb_elements(t_data *data, char **arr, t_sur sur)
{
	char	**colors;

	data->rgb[sur].id = ft_strdup(arr[0]);
	colors = ft_split(arr[1], ',');
	if (colors[0] == NULL || colors[1] == NULL || colors[2] == NULL
		|| colors[3] != NULL)
	{
		destroy_array_str(colors);
		return (1);
	}
	if (are_color_values_valid(colors) == false)
		return (1);
	data->rgb[sur].red = ft_atoi(colors[0]);
	data->rgb[sur].green = ft_atoi(colors[1]);
	data->rgb[sur].blue = ft_atoi(colors[2]);
	if (data->rgb[sur].red > 0xFF || data->rgb[sur].green > 0xFF
		|| data->rgb[sur].blue > 0xFF)
		return (1);
	data->rgb[sur].parsed = true;
	destroy_array_str(colors);
	return (0);
}

static bool	are_color_values_valid(char **arr)
{
	size_t	i;
	size_t	n_colors;

	i = 0;
	n_colors = 3;
	while (i < n_colors)
	{
		if (contains_only_digits(arr[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

static bool	contains_only_digits(char *s)
{
	size_t	i;
	size_t	num_digits;

	i = 0;
	num_digits = 0;
	while (s[i] != '\0')
	{
		while (ft_isspace(s[i]) == true)
			i++;
		if (ft_isdigit(s[i]) == false)
			return (false);
		num_digits++;
		if (num_digits > 3)
			return (false);
		i++;
	}
	return (true);
}
