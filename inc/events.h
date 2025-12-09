/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspari <sgaspari@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 11:56:29 by sgaspari          #+#    #+#             */
/*   Updated: 2025/12/09 11:10:04 by sgaspari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
#define EVENTS_H

int		handle_events(int keysym, t_data *data);
void	move(int keysym, t_data *data);
void	turn(int keysym, t_data *data);
int		quit(t_data *data);

#endif
