/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 15:34:53 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/10 09:45:15 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

typedef struct s_data t_data;

typedef enum e_num
{
	MATRIX,
	MAP
}	t_num;

void	print_error(char *s);
void	print_map(t_data *data, t_num num);

#endif
