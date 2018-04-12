/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 23:02:46 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/11 23:07:43 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "lemin.h"

int			count_links(t_room *room)
{
	t_link	*ptr;
	int		i;

	i = 0;
	ptr = room->links;
	while (ptr)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

void		create_links(t_room *room)
{
	int		count;
	int		i;
	t_link	*ptr;

	count = count_links(room);
	room->nodes = ft_memalloc((count + 1) * sizeof(struct s_room *));
	i = 0;
	ptr = room->links;
	while (i < count)
	{
		room->nodes[i] = ptr->parent;
		ptr = ptr->next;
		i++;
	}
	room->nodes[i] = NULL;
}

void	clean_rooms(t_room	**all_rooms)
{
	int	i;

	i = 0;
	while (all_rooms[i] != NULL)
	{
		all_rooms[i]->next = NULL;
		all_rooms[i]->prev = NULL;
		i++;
	}
}
