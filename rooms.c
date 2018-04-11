/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:06:14 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/10 17:29:55 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_room(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	else if ((ft_space(line)) == 2)
		return (1);
	return (0);
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

int		is_comment(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (1);
	else
		return (0);
}


void	print_rooms(t_ants *ants)
{
	t_room		*temp;
	temp = ants->rooms;
	while (temp != NULL)
	{
		ft_printf("here is the room: %s, it's position %d ", temp->name, temp->position);
		if (temp->is_start == 1)
			ft_printf("its start room");
		else if (temp->is_end == 1)
			ft_printf("it's end room");
		ft_putchar('\n');
		temp = temp->next;
	}
}

t_room	*find_room(t_room *room, char *name)
{
	t_room *temp;

	temp = room;
	while (ft_strcmp(temp->name, name) != 0)
		temp = temp->next;
	return (temp);
}