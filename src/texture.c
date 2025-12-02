/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:22:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 12:25:25 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "data.h"
#include "destroy.h"
#include "libft.h"
#include <stdbool.h>
#include <sys/types.h>

static void	fill_tex_elements(t_data *data, char **arr, t_card card);

bool	is_texture(t_data *data, char *s)
{
	if (ft_strncmp("NO ", s, 3) == 0 && data->tex[NO].parsed == false)
		return (true);
	else if (ft_strncmp("SO ", s, 3) == 0 && data->tex[SO].parsed == false)
		return (true);
	else if (ft_strncmp("EA ", s, 3) == 0 && data->tex[EA].parsed == false)
		return (true);
	else if (ft_strncmp("WE ", s, 3) == 0 && data->tex[WE].parsed == false)
		return (true);
	else
		return (false);
}

void	parse_texture(t_data *data, char *s)
{
	char	**arr;

	arr = ft_split(s, ' ');
	if (ft_strncmp("NO", arr[0], 3) == 0)
		fill_tex_elements(data, arr, NO);
	else if (ft_strncmp("SO", arr[0], 3) == 0)
		fill_tex_elements(data, arr, SO);
	else if (ft_strncmp("EA", arr[0], 3) == 0)
		fill_tex_elements(data, arr, EA);
	else if (ft_strncmp("WE", arr[0], 3) == 0)
		fill_tex_elements(data, arr, WE);
	if (data->tex[NO].parsed == true 
			&& data->tex[SO].parsed == true
			&& data->tex[EA].parsed == true
			&& data->tex[WE].parsed == true)
		data->tex_parsed = true;
	destroy_array_str(arr);
}

static void	fill_tex_elements(t_data *data, char **arr, t_card card)
{
	data->tex[card].id = ft_strdup(arr[0]);
	data->tex[card].path = ft_strdup(arr[1]);
	data->tex[card].parsed = true;
}
