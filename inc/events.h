/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:56:29 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/11 16:33:08 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

int		handle_keypress(int keysym, t_data *data);
int		handle_keyrelease(int keysym, t_data *data);
void	move(int keysym, t_data *data);
void	toggle_door(t_data *data);
void	turn(int keysym, t_data *data);
int		quit(t_data *data);

#endif
