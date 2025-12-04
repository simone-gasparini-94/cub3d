#include "data.h"
#include "destroy.h"
#include <X11/keysym.h>
#include <stdio.h>


int	handle_key_presses(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		quit(data);
	return (0);
}
