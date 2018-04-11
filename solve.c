/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:35:10 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/10 18:01:04 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	ft_solve (t_ants *ants)
{
	int		start;
	int		end;
	t_room	*temp;

	start = 0;
	end = 0;
	temp = ants->rooms;
	while (temp)
	{
		if (temp->is_start == 1)
			start = 1;
		if (temp->is_end == 1)
			end = 1;
		temp = temp->next;
	}
	if (start != 1 || end != 1)
		ft_error();
	if (ants->rooms->is_start != 1)
		ants->rooms = start_move(ants->rooms);
	temp = last_room(ants->rooms);
	if (temp->is_end != 1)
		ants->rooms = end_move(ants->rooms);
	print_rooms(ants);  //test
	print_links(ants);  //test
	find_path(ants);
}

void	find_path(t_ants *ants)
{
	t_room	*room;
	t_room	*head;
	t_room	*temp;
	char 	*end;

	room = ants->rooms;
	head = ants->rooms;
	temp = NULL;
	room->visited = 1;
	ft_printf("Start: %s -> ", room->name);
	while (room->is_end != 1)
		room = room->next;
	end = ft_strdup(room->name);
		room = head;
		while (ft_strcmp(end, room->links->name2) != 0)
		{
			while (room->links)
			 if (room->links->seen != 0)
				room->links = room->links->next;
			ft_printf("%s -> ", room->links->name2);
			room->links->seen = 1;
			if (temp == NULL)
				temp = find_room(head, room->links->name2);
			else
				while (temp->next != NULL)
					temp = temp->next;
				temp->next = find_room(head, room->links->name2);
			temp->prev = room;
			room->visited = 1;
			room = room->next;
			// ft_printf("%s -> ", room->name);
			// room->links->seen = 1;
			// room->links = room->links->next;
			// room->visited = 1;
			// while (room->visited != 0)
			// 	room = room->next;
			// room->links->seen = 1;
			// ft_printf("visited: %s\n", room->name);
		}
		// ft_printf("%s -> ", room->next->name);
}


