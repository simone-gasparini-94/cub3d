#include "textures.h"
#include "data.h"
#include "libft.h"
#include <stdbool.h>
#include <sys/types.h>

#define CARDINAL_POINTS 4

static bool	contains_cardinal(char *str);

int    parse_textures(t_data *data, char **array, ssize_t len)
{
	size_t	i;
	size_t	j;
	char	**arr;

	i = 0;
	j = 0;
	while (i < (size_t) len)
	{
		if (j >= CARDINAL_POINTS)
			break ;
		if (contains_cardinal(array[i]) == true)
		{
			arr = ft_split(array[i], ' ');
			data->tex[j].id = arr[0];
			data->tex[j].path = arr[1];
			j++;
		}
		i++;
	}
	return (0);
}

static bool	contains_cardinal(char *str)
{
	return (ft_strncmp(str, "NO ", 3) == 0
		|| ft_strncmp(str, "SO ", 3) == 0
		|| ft_strncmp(str, "WE ", 3) == 0
		|| ft_strncmp(str, "EA ", 3) == 0);
}
	
