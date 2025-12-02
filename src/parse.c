/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:55:35 by duccello          #+#    #+#             */
/*   Updated: 2025/12/02 14:32:46 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "data.h"
#include "map.h"
#include "get_next_line.h"
#include "libft.h"
#include "ft_fprintf.h"
#include "parse.h"
#include "texture.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static bool		check_extension(char *file);
static char		*add_path_to_file(char *s);
static int		parse_file(t_data *data, char *file);

int	parse(t_data *data, char *file)
{
	char	*file_with_path;

	if (check_extension(file) == false)
	{
		ft_fprintf(STDERR_FILENO, "ERROR: Wrong extension\n");
		return (1);
	}
	file_with_path = add_path_to_file(file);
	if (parse_file(data, file_with_path) == 1)
	{
		ft_fprintf(STDERR_FILENO, "ERROR: Invalid file\n");
		return (1);
	}
	printf("Map has %zu rows\n", data->map.rows);
	for (size_t i = 0; i < data->map.rows; i++)
		printf("%s", data->map.matrix[i]);
	free(file_with_path);
	return (0);
}

static bool		check_extension(char *file)
{
	size_t	len;
	
	if (file == NULL)
		return (false);	
	len = ft_strlen(file);
	return (len >= 4 && file[len - 4] == '.' && file[len - 3] == 'c'
			&& file[len - 2] == 'u' && file[len - 1] == 'b');
}

static char		*add_path_to_file(char *s)
{
	char	*new_str;

	new_str = ft_strjoin("assets/", s);
	return (new_str);
}

static int		parse_file(t_data *data, char *file)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror("open");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (is_texture(data, line) == true)
			parse_texture(data, line);
		else if (is_color(data, line) == true)
			parse_color(data, line);
		else if (is_map(data, line) == true)
		{
			if (parse_map(data, line, fd) == 1)
				return (1);
		}
		else if (line[0] == '\n' || line[0] == '\0')
			;
		else
		{
			free(line);
			return (1);
		}
		if (line != NULL)
			free(line);
	}
	close(fd);
	return (0);
}
