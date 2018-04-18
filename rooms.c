/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:06:14 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/17 21:48:12 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*find_room(t_room *room, char *name)
{
	t_room *temp;

	temp = room;
	while (ft_strcmp(temp->name, name) != 0)
		temp = temp->next;
	return (temp);
}

void	add_room(t_ants *ants, char *line)
{
	int			i;
	t_room		*new;
	t_room		*temp;

	i = 0;
	ants->room_count++;
	new = (t_room *)malloc(sizeof(t_room));
	init_room(new);
	while (line[i] != ' ')
		i++;
	new->name = ft_strndup(line, i);
	new->position = ants->room_count;
	if (ants->flag == 1)
		new->is_start = 1;
	if (ants->flag == 2)
		new->is_end = 1;
	if (ants->rooms == NULL)
		ants->rooms = new;
	else
	{
		temp = ants->rooms;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prev = temp;
	}
	ants->flag = 0;
}

void	link_to_room(t_room *temp, t_link *new)
{
	t_link	*add;

	if (temp->links == NULL)
		temp->links = new;
	else if (same_link(temp, new) != 1)
	{
		add = temp->links;
		while (add->next != NULL)
			add = add->next;
		add->next = new;
	}
}
