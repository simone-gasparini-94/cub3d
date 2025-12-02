#include <X11/keysym.h>

static void	turn_right(t_data *data, data->map t_map *map);
static void	turn_left(t_data *data, data->map t_map *map);
static void	move_foward(t_data *data, data->map t_map *map);
static void	move_back(t_data *data, data->map t_map *map);
static void	move_left(t_data *data, data->map t_map *map);
static void	move_right(t_data *data, data->map t_map *map);

void	key_presses(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit(ptr);
	if (keysym == XK_Right)
		turn_right(data, data->map);
	if (keysym == XK_Left)
		turn_left(data, data->map);
	if (keysym == XK_w || keysym == XK_W)
		move_foward(data, data->map);
	if (keysym == XK_s || keysym == XK_S)
		move_back(data, data->map);
	if (keysym == XK_a || keysym == XK_a)
		move_left(data, data->map);
	if (keysym == XK_d || keysym == XK_D)
		move_right(data, data->map);
}

static void	turn_right(t_data *data, data->map t_map *map)
{
	printf("turn_right pressed");
	return ;
}

static void	turn_left(t_data *data, data->map t_map *map)
{
	printf("turn_left pressed");
	return ;
}
static void	move_foward(t_data *data, data->map t_map *map)
{
	printf("move_foward pressed");
	return ;
}
static void	move_back(t_data *data, data->map t_map *map)
{
	printf("move_back pressed");
	return ;
}
static void	move_right(t_data *data, data->map t_map *map)
{
	printf("move_right pressed");
	return ;
}
static void	move_left(t_data *data, data->map t_map *map)
{
	printf("move_left pressed");
	return ;
}
