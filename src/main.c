/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 15:55:43 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/01 17:17:34 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "ft_fprintf.h"
#include "parse.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main(int argc, char *argv[])
{
	t_data	*data;

	data = create_data();
	if (data == NULL)
		return (1);
	if (argc != 2)
	{
		ft_fprintf(STDERR_FILENO, "ERROR: Invalid number of arguments.\n");
		return (1);
	}
	if (parse(data, argv[1]) != 1)
	{
		// interpret();
		// clean();
	}
	return (0);
}
