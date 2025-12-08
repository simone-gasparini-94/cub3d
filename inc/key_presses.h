/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:56:29 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/08 11:58:29 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_PRESSES_H
#define KEY_PRESSES_H

typedef struct s_dir
{
	int	f;
	int	b;
	int	l;
	int	r;
}	t_dir;

int	handle_key_presses(int keysym, t_data *data);

#endif
