/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:17:08 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 14:02:20 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "map.h"
#include "libft.h"
#include "get_next_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

static bool	contains_valid_chars(char *s);
static t_node		*create_node(char *s);
static void	convert_list_to_matrix(t_data *data, t_node *head);

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
	char	*line;
	int		ret;

	ret = 0;
	head = create_node(s);
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
		curr->next = create_node(line);
		curr = curr->next;
	}
	data->map_parsed = true;
	convert_list_to_matrix(data, head);
	return (ret);
}

static t_node		*create_node(char *s)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == NULL)
		return (NULL);
	node->s = ft_strdup(s);
	node->next = NULL;
	free(s);
	return (node);
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

static void	convert_list_to_matrix(t_data *data, t_node *head)
{
	t_node	*curr;
	size_t	i;

	curr = head;
	i = 0;
	while (curr != NULL)
	{
		i++;
		curr = curr->next;
	}
	data->map.rows = i;
	data->map.matrix = calloc(i, sizeof(char *));
	curr = head;
	i = 0;
	while (curr != NULL)
	{
		data->map.matrix[i++] = ft_strdup(curr->s);
		curr = curr->next;
	}
}
