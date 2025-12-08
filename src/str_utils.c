#include "libft.h"

void ft_skip_spaces(char **s)
{
    while (**s == ' ')
        (*s)++;
    return ;
}

char		*add_path_to_file(char *s)
{
	char	*new_str;

	new_str = ft_strjoin("assets/", s);
	return (new_str);
}

size_t ft_arraylen(char    **array)
{
    size_t i;

    if  (array == NULL)
        return (0);
    i = 0;
    while (array[i] != NULL)
        i++;
    return (i);
}