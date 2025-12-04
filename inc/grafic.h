#ifndef GRAFIC_H
# define GRAFIC_H

typedef struct s_grph
{
	void	*mlx;
	void	*win;

}			t_grph;

int			initate_mlx(t_data *data);
void		render(t_data *data);


#endif