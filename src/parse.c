/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:55:35 by duccello          #+#    #+#             */
/*   Updated: 2025/12/03 16:39:25 by sgaspari         ###   ########.fr       */
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
		ft_fprintf(STDERR_FILENO, "Error\nLine %d is invalid\n", data->file_line);
		return (1);
	}
	print_values(data);
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
	int		fd;
	char	*line;
	char	*tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	while (1)
	{
		tmp = get_next_line(fd);
		if (tmp == NULL)
			break ;
		data->file_line++;
		line = ft_strtrim(tmp, "\n");
		free(tmp);
		if (parse_line(data, line, fd) == 1)
		{
			free(line);
			return (1);
		}
		free(line);
	}
	close(fd);
	return (0);
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

void	print_values(t_data *data)
{
	size_t	i;

	printf("\n");
	i = 0;
	while (i < data->map.rows)
		printf("%s\n", data->map.matrix[i++]);
	printf("\n");
	printf("%s:\t%d, %d, %d\n", data->rgb[F].id, data->rgb[F].red, data->rgb[F].green, data->rgb[F].blue);
	printf("%s:\t%d, %d, %d\n", data->rgb[C].id, data->rgb[C].red, data->rgb[C].green, data->rgb[C].blue);
	printf("\n");
	printf("%s:\t%s\n", data->tex[NO].id, data->tex[NO].path);
	printf("%s:\t%s\n", data->tex[SO].id, data->tex[SO].path);
	printf("%s:\t%s\n", data->tex[EA].id, data->tex[EA].path);
	printf("%s:\t%s\n", data->tex[WE].id, data->tex[WE].path);
	printf("\n");
}
