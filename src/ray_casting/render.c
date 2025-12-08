#include "data.h"
#include <mlx.h>

void    render(t_data   *data)
{
    mlx_put_image_to_window(data->grph.mlx, data->grph.win, data->tex[NO].texture, 0, 0);
    mlx_put_image_to_window(data->grph.mlx, data->grph.win, data->tex[SO].texture, 256, 0);
}