/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:06:14 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/30 23:06:27 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

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
	t_ants		*temp;

	i = 0;
	ants->room_count++;
	temp = ants;
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
	if (temp->rooms == NULL)
		temp->rooms = new;
	else
	{
		while (temp->rooms != NULL)
			temp->rooms = temp->rooms->next;
		// temp->rooms = (t_room *)malloc(sizeof(t_room));
		temp->rooms = new;
		// temp->rooms->name = new->name;
	}
	ants->flag = 0;
	// free(new->name);
	// free(new);
	print_rooms(ants);
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
	t_ants		*temp;
	temp = ants;
	while (temp->rooms != NULL)
	{
		ft_printf("here is the room: %s, it's position %d ", temp->rooms->name, temp->rooms->position);
		if (temp->rooms->is_start == 1)
			ft_printf("its start room");
		else if (temp->rooms->is_end == 1)
			ft_printf("it's end room");
		ft_putchar('\n');
		temp->rooms = temp->rooms->next;
	}
}