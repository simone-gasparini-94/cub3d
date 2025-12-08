#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

static char	*populate(const char **s, char c, size_t i);
static void	free_arr(char **s, size_t rows);

char	**ft_split_once(const char *s, char c)
{
	char	**arr;
	size_t	n_str;
	size_t	i;

	n_str = 2;
	arr = calloc(n_str + 1, sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < n_str)
	{
		arr[i] = populate(&s, c, i);
		if (arr[i] == NULL)
		{
			free_arr(arr, i);
			return (NULL);
		}
		i++;
	}
	return (arr);
}

static char	*populate(const char **s, char c, size_t i)
{
	size_t	len;
	char	*str;

	len = 0;
	while (c == **s && **s)
		(*s)++;
	if (i == 0)
	{
		while (c != **s && **s)
		{
			len++;
			(*s)++;
		}
	}
	else
	{
		while (**s)
		{
			len++;
			(*s)++;
		}
	}
	str = calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, *s - len, len + 1);
	return (str);
}

static void	free_arr(char **s, size_t rows)
{
	size_t	i;

	i = 0;
	while (i < rows)
		free(s[i++]);
	free(s);
}
