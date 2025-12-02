#include "data.h"
#include "graphic.h"
#include <mlx.h>

void	initiate_mlx_images(t_data *data);

int	initate_mlx(t_data *data)
{
	data->grph.mlx = mlx_init();
	if (data->grph.mlx == NULL)
	{
		perror("MLX");
		// quit();
	}
	data->grph.mlx = mlx_new_window(data->grph.mlx, 1080, 720, "Test_numero_1");
	if (data->grph.win == NULL)
	{
		perror("MLX");
		// quit();
	}
	initiate_mlx_images(data);
	render(data);
	mlx_hook(data->grph.win, KeyPress, KeyPressMask, key_presses, data);
	mlx_loop(data->grph.mlx);
}

void	initate_mlx_images(t_data *data)
{
	data->tex[NO].texture = mlx_xpm_file_to_image(data->graph->mlx,
			data->tex[NO].path, width, height);
	data->tex[SO].texture = mlx_xpm_file_to_image(data->graph->mlx,
			data->tex[SO].path, width, height);
	data->tex[WE].texture = mlx_xpm_file_to_image(data->graph->mlx,
			data->tex[WE].path, width, height);
	data->tex[EA].texture = mlx_xpm_file_to_image(data->graph->mlx,
			data->tex[EA].path, width, height);
}

void	render(t_data *data)
{
	return ;
}