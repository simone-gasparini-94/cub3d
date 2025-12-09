#include "libft.h"
#include "stdio.h"
#include "stdlib.h"
#include "data.h"

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

char    **copy_matrix(t_data *data)
{
    char    **new_matrix;
    size_t  i;

    new_matrix = malloc(sizeof(char *) * (data->map.rows + 1));
    i = 0;
    while (i < data->map.rows)
    {
        new_matrix[i] = ft_strdup(data->map.matrix[i]); 
        i++;
    }
    new_matrix[i] = NULL;
    new_matrix[data->map.player_y][data->map.player_x] = '0';
    data->map.empty_spaces += 1;
    return (new_matrix);
}
