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
    size_t  j;

    new_matrix = malloc(sizeof(char *) * (data->map.rows + 1));
    i = 0;
    while (i < data->map.rows)
    {
        j = 0;
        new_matrix[i] = malloc(sizeof(char) * (ft_strlen(data->map.matrix[i]) + 1));
        while (data->map.matrix[i][j])
        {
            new_matrix[i][j] = data->map.matrix[i][j];
            j++;
        }
        i++;
    }
    new_matrix[i] = NULL;
    new_matrix[data->map.player_y][data->map.player_x] = '0';
    data->map.empty_spaces += 1;
    return (new_matrix);
}