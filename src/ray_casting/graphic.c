#include "data.h"
#include "destroy.h"
#include "ft_fprintf.h"
#include <mlx.h>
#include <stdlib.h>
#include <unistd.h>

static int	init_mlx_images(t_data *data);
static void	init_graphic_values(t_data *data);

int	init_mlx(t_data *data)
{
	init_graphic_values(data);
	data->grph.mlx = mlx_init();
	if (data->grph.mlx == NULL)
	{
		ft_fprintf(STDERR_FILENO, "Error\nMLX Initialization Failed\n");
		return (1);
	}
	data->grph.win = mlx_new_window(data->grph.mlx, data->grph.window_width,
			data->grph.window_height, "Test_numero_1");
	if (data->grph.win == NULL)
	{
		ft_fprintf(STDERR_FILENO, "Error\nMLX New Window Failed\n");
		return (1);
	}
	if (init_mlx_images(data) == 1)
	{
		ft_fprintf(STDERR_FILENO, "Error\nInvalid Path to Texture\n");
		return (1);
	}

	return (0);
}

static void	init_graphic_values(t_data *data)
{
	data->grph.texture_width = 256;
	data->grph.texture_height = 256;
	data->grph.window_width = 1080;
	data->grph.window_height = 720;
}

int	init_mlx_images(t_data *data)
{
	data->tex[NO].texture = mlx_xpm_file_to_image(data->grph.mlx,
			data->tex[NO].path, &data->grph.texture_width,
			&data->grph.texture_height);
	data->tex[SO].texture = mlx_xpm_file_to_image(data->grph.mlx,
			data->tex[SO].path, &data->grph.texture_width,
			&data->grph.texture_height);
	data->tex[EA].texture = mlx_xpm_file_to_image(data->grph.mlx,
			data->tex[EA].path, &data->grph.texture_width,
			&data->grph.texture_height);
	data->tex[WE].texture = mlx_xpm_file_to_image(data->grph.mlx,
			data->tex[WE].path, &data->grph.texture_width,
			&data->grph.texture_height);
	if (data->tex[NO].texture == NULL || data->tex[SO].texture == NULL
		|| data->tex[WE].texture == NULL || data->tex[EA].texture == NULL)
		return (1);
	return (0);
}
