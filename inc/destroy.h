/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 12:25:45 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/02 14:10:28 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DESTROY_H
# define DESTROY_H

typedef struct s_data	t_data;
typedef struct s_node	t_node;

void					destroy_data(t_data *data);
void					destroy_array_str(char **arr);
void					destroy_list(t_node *head);
int					quit(t_data *data);

#endif
