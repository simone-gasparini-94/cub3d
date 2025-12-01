/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:22:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/01 17:56:51 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "texture.h"
#include "data.h"
#include "libft.h"
#include <stdbool.h>
#include <sys/types.h>

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
	{
		data->tex[NO].id = arr[0];
		data->tex[NO].path = arr[1];
		data->tex[NO].parsed = true;
	}
	else if (ft_strncmp("SO", arr[0], 3) == 0)
	{
		data->tex[SO].id = arr[0];
		data->tex[SO].path = arr[1];
		data->tex[SO].parsed = true;
	}
	else if (ft_strncmp("EA", arr[0], 3) == 0)
	{
		data->tex[EA].id = arr[0];
		data->tex[EA].path = arr[1];
		data->tex[EA].parsed = true;
	}
	else if (ft_strncmp("WE", arr[0], 3) == 0)
	{
		data->tex[WE].id = arr[0];
		data->tex[WE].path = arr[1];
		data->tex[WE].parsed = true;
	}
}
