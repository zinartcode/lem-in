/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 22:29:16 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/20 18:05:49 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room		*start_move(t_room *room)
{
	t_room	*start;
	t_room	*temp;

	temp = room;
	while (temp->next != NULL && temp->is_start != 1)
		temp = temp->next;
	start = temp;
	temp->prev->next = temp->next;
	temp = room;
	start->next = room;
	return (start);
}

t_room		*end_move(t_room *room)
{
	t_room	*end;
	t_room	*temp;
	t_room	*head;

	head = room;
	temp = room;
	while (temp && temp->is_end != 1)
		temp = temp->next;
	end = temp;
	temp->prev->next = temp->next;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = end;
	end->prev = temp;
	end->next = NULL;
	return (head);
}

t_room		*last_room(t_room *room)
{
	t_room	*temp;

	temp = room;
	while (temp->next != NULL)
		temp = temp->next;
	return (temp);
}
