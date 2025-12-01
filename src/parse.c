/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: duccello <duccello@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 12:55:35 by duccello          #+#    #+#             */
/*   Updated: 2025/12/01 15:32:33 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "data.h"
#include "get_next_line.h"
#include "libft.h"
#include "parse.h"
#include "textures.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

static ssize_t	find_file_len(char *path);
static void		populate_array(char **array, char *path, ssize_t len);

int	parse(t_data *data, char *file)
{
	char	*path;
	ssize_t	len;
	char	**array;

	path = ft_strjoin("assets/", file);
	if (!path)
	{
		perror("Malloc");
		return (1);
	}
	len = find_file_len(path);
	array = malloc(len * sizeof(char *));
	if (!array)
	{
		perror("Malloc");
		return (1);
	}
	populate_array(array, path, len);
	if (parse_textures(data, array, len) == 1)
	{
		printf("Hi\n");
		return (1);
	}
	for (int i = 0; i < 4; i++)
		printf("%d: %s | %s\n", i, data->tex[i].id, data->tex[i].path);
	/* if (parse_colors(data, array, len) == 1)
		return (1);
	if (parse_map(data, array, len) == 1)
		return (1); */
	return (0);
}

static ssize_t	find_file_len(char *path)
{
	int		fd;
	size_t	len;
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Open");
		return (-1);
	}
	len = 0;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		len++;
		free(str);
	}
	close(fd);
	return (len);
}

static void	populate_array(char **array, char *path, ssize_t len)
{
	size_t i;
	int fd;

	i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Open");
		close(fd);
		return ;
	}
	while (i < (size_t)len)
	{
		array[i] = get_next_line(fd);
		i++;
	}
	close(fd);
}
