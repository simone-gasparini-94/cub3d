/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:17:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/03 16:51:59 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include <mlx.h>
#include <stdlib.h>

void	destroy_data(t_data *data)
{
	(void)data;
}

void	destroy_array_str(char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	destroy_list(t_node *head)
{
	t_node	*curr;
	t_node	*prev;

	prev = head;
	curr = prev->next;
	while (curr != NULL)
	{
		free(prev->s);
		free(prev);
		prev = curr;
		curr = curr->next;
	}
	free(prev->s);
	free(prev);
}

int	quit(t_data *data)
{
	mlx_loop_end(data->grph.mlx);
	return (0);
}