/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:43:55 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/18 02:02:50 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init(t_ants *ants)
{
	ants->ant_count = 0;
	ants->room_count = 0;
	ants->flag = 0;
	ants->start_end = 0;
	ants->rooms = NULL;
	ants->paths = NULL;
	ants->temp_path = NULL;
}

void	init_room(t_room *room)
{
	room->name = NULL;
	room->is_start = 0;
	room->is_end = 0;
	room->position = 0;
	room->number_of_ant = 0;
	room->visited = 0;
	room->links = NULL;
	room->prev = NULL;
	room->next = NULL;
}

void	init_link(t_link *link)
{
	link->name1 = NULL;
	link->name2 = NULL;
	link->seen = 0;
	link->is_path = 0;
	link->shortest = 0;
	link->len = 0;
	link->parent = NULL;
	link->path = NULL;
	link->next = NULL;
}
