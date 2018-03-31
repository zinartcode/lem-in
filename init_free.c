/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 19:43:55 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/30 23:56:57 by asarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	init(t_ants *ants)
{
	ants->ant_count = 0;
	ants->room_count = 0;
	ants->flag = 0;
	ants->rooms = NULL;
	ants->paths = NULL;
}

void	init_room(t_room *room)
{
	room->name = NULL;
	room->is_start = 0;
	room->is_end = 0;
	room->position = 0;
	room->visited = 0;
	room->links = NULL;
	room->next = NULL;
}

void	init_link(t_link *link)
{
	link->name = NULL;
	link->seen = 0;
	link->is_path = 0;
	link->shortest = 0;
	link->number_of_ant = 0;
	link->len = 0;
	link->path = NULL;
	link->next = NULL;
}
