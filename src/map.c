/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:17:08 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 12:03:16 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "map.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdlib.h>
#include <stdbool.h>

static bool	contains_valid_chars(char *s);

bool	is_map(t_data *data, char *s)
{
	return (contains_valid_chars(s)
			&& data->map_parsed == false
			&& data->tex_parsed == true
			&& data->rgb_parsed == true);
}

int		parse_map(t_data *data, char *s, int fd)
{
	t_node	*head;
	t_node	*curr;
	t_node	*node;
	char	*line;
	int		ret;

	ret = 0;
	head = malloc(sizeof(t_node));
	head->s = ft_strdup(s);
	head->next = NULL;
	curr = head;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		if (line[0] == '\n')
		{
			free(line);
			break;
		}
		else if (is_map(data, line) == false)
		{
			free(line);
			ret = 1;
			break;
		}
		node = malloc(sizeof(t_node));
		node->s = ft_strdup(line);
		node->next = NULL;
		curr->next = node;
		curr = curr->next;
		free(line);
	}
	data->map_parsed = true;
	data->map.list = head;
	return (ret);
}

static bool	contains_valid_chars(char *s)
{
	bool	contains_char;
	size_t	i;

	contains_char = false;
	i = 0;
	while (s[i] != '\n' && s[i] != '\0')
	{
		if (!ft_isspace(s[i])
				&& s[i] != '0' && s[i] != '1'
				&& s[i] != 'N' && s[i] != 'S'
				&& s[i] != 'E' && s[i] != 'W')
			return (false);
		if (s[i] == '0' || s[i] == '1'
				|| s[i] == 'N' || s[i] == 'S'
				|| s[i] == 'E' || s[i] == 'W')
			contains_char = true;
		i++;
	}
	return (i > 0 && contains_char);
}
