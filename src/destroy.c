/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:17:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/08 16:54:08 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "data.h"
#include "destroy.h"
#include <mlx.h>
#include <stdlib.h>

#define CARDINAL_POINTS 4

static void	destroy_tex_elements(t_data *data);
static void	destroy_rgb_elements(t_data *data);

void	destroy_data(t_data *data)
{
	if (data != NULL)
	{
		destroy_tex_elements(data);
		destroy_rgb_elements(data);
		if (data->grph.img.img != NULL)
			mlx_destroy_image(data->grph.mlx, data->grph.img.img);
		if (data->grph.win != NULL)
			mlx_destroy_window(data->grph.mlx, data->grph.win);
		if (data->grph.mlx != NULL)
		{
			mlx_destroy_display(data->grph.mlx);
			free(data->grph.mlx);
		}
		if (data->map.matrix != NULL)
			destroy_array_str(data->map.matrix);
		free(data);
	}
}

void	destroy_array_str(char **arr)
{
	size_t	i;

	i = 0;
	if (arr == NULL)
		return ;
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

	if (head == NULL)
		return ;
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

static void	destroy_tex_elements(t_data *data)
{
	size_t	card;

	card = 0;
	while (card < CARDINAL_POINTS)
	{
		if (data->tex[card].id != NULL)
			free(data->tex[card].id);
		if (data->tex[card].path != NULL)
			free(data->tex[card].path);
		if (data->tex[card].texture != NULL)
			mlx_destroy_image(data->grph.mlx, data->tex[card].texture);
		card++;
	}
}

static void	destroy_rgb_elements(t_data *data)
{
	if (data->rgb[C].id != NULL)
		free(data->rgb[C].id);
	if (data->rgb[F].id != NULL)
		free(data->rgb[F].id);
}

int	quit(t_data *data)
{
	mlx_loop_end(data->grph.mlx);
	return (0);
}
