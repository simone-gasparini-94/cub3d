#ifndef GRAPHIC_H
# define GRAPHIC_H

typedef struct s_grph
{
	void	*mlx;
	void	*win;
	int		texture_width;
	int		texture_height;
	int		window_width;
	int		window_height;
}			t_grph;

int			init_mlx(t_data *data);
void		render(t_data *data);

#endif