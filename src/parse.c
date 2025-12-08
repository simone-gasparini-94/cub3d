/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:55:35 by duccello          #+#    #+#             */
/*   Updated: 2025/12/08 16:47:24 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "get_next_line.h"
#include "libft.h"
#include "ft_fprintf.h"
#include "parse.h"
#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static bool		check_extension(char *file);
static int		parse_file(t_data *data, char *file);
static int		parse_line(t_data *data, char *line, int fd);

int	parse(t_data *data, char *file)
{
	char	*file_with_path;

	if (check_extension(file) == false)
	{
		ft_fprintf(STDERR_FILENO, "Error\nWrong extension\n");
		return (1);
	}
	file_with_path = add_path_to_file(file);
	if (parse_file(data, file_with_path) == 1)
	{
		ft_fprintf(STDERR_FILENO, "Error\nLine %d is invalid\n",
				data->file_line);
		free(file_with_path);
		return (1);
	}
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

static int		parse_file(t_data *data, char *file)
{
	int		fd;
	int		ret;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	ret = 0;
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		if (ret == 0)
			data->file_line++;
		line = ft_strtrim(tmp, "\n");
		free(tmp);
		if (ret == 0 && parse_line(data, line, fd) == 1)
			ret = 1;
		free(line);
	}
	close(fd);
	return (ret);
}

static	int		parse_line(t_data *data, char *line, int fd)
{
	if (is_texture(data, line) == true)
		return (parse_texture(data, line));
	else if (is_color(data, line) == true)
		return (parse_color(data, line));
	else if (is_map(data, line) == true)
		return (parse_map(data, line, fd));
	else if (line[0] == '\0')
		return (0);
	else
		return (1);
}

