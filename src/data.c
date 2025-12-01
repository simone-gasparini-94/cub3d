/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:52:47 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/01 17:53:10 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <stdlib.h>
#include <stdio.h>

t_data	*create_data(void)
{
	t_data *data;

	data = calloc(1, sizeof(t_data));
	if (data == NULL)
	{
		perror("malloc");
		return (NULL);
	}
	return (data);
}
