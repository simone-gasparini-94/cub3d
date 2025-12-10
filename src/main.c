/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:55:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 09:46:25 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "destroy.h"
#include "ft_fprintf.h"
#include "parse.h"
#include "print.h"
#include "graphic.h"
#include <mlx.h>
#include "events.h"
#include <X11/X.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = create_data();
	if (data == NULL)
		return (1);
	if (argc != 2)
	{
		ft_fprintf(STDERR_FILENO, "Error\nInvalid number of arguments.\n");
		return (1);
	}
	if (parse(data, argv[1]) == 0 && init_mlx(data) == 0)
	{
		mlx_hook(data->grph.win, DestroyNotify, 0, &quit, data);
		mlx_hook(data->grph.win, KeyPress, KeyPressMask, 
			&handle_events, data);
		render(data);
		mlx_loop(data->grph.mlx);
		//clean_mlx
	}
	destroy_data(data);
	return (0);
}
