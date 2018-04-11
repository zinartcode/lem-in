/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:35:10 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/10 22:01:08 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		count_links(t_room *room)
{
	t_link *ptr;
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

void	create_links(t_room *room)
{
	int count;
	int i;
	t_link *ptr;

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

void	find_paths(t_room *root)
{
	t_room	*ptr;
	t_room	*original;
	int		i;

	i = 0;
	original = root;
	ptr = root;
	while (ptr)
	{
		create_links(ptr);
		ptr = ptr->next;
	}
	ptr = root;
	while (ptr)
	{
		all_rooms[i] = ptr;
		i++;
		ptr = ptr->next;
	}
	all_rooms[i] = NULL;
	find_paths_2(root, ptr);
}


void	find_paths_2(t_room *root, t_room *ptr)
{
	int	i;

	i = 0;
	while (all_rooms[i] != NULL)
	{
		all_rooms[i]->next = NULL;
		all_rooms[i]->prev = NULL;
		i++;
	}
	ptr = root;
	while (root)
	{
		root->visited = 1;
		i = 0;
		while (root->nodes[i] != NULL)
		{
			if (root->nodes[i]->visited == 0)
			{
				root->nodes[i]->visited = 1;
				ptr->next = root->nodes[i];
				ptr = ptr->next;
				ptr->prev = root;
			}
			i++;
		}
		root = root->next;
	}
	store_path(ptr);
}

void			store_path(t_room *room)
{
	t_room		*ptr;
	t_room		*finish;
	t_room		*start;
	int			i;

	ptr = room;
	i = 0;

	while (all_rooms[i] != NULL)
	{
		if (all_rooms[i]->is_end == 1)
			finish = all_rooms[i];
		if (all_rooms[i]->is_start == 1)
			start = all_rooms[i];

		i++;
	}

	printf("end room is %s\n", ptr->name);
	ptr = finish;
	while (ptr != start)
	{
		printf("backtracking, .. \n");
		printf("current room is %s \n", ptr->name);
		ptr = ptr->prev;
		if (ptr == NULL)
			break ;

	}
	printf("final room is %s\n", ptr->name);
	return ;	
}

void	ft_solve (t_ants *ants)
{
	int		start;
	int		end;
	t_room	*temp;

	all_rooms = ft_memalloc(sizeof(struct s_room *) * (ants->room_count + 1));

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
	// print_rooms(ants);  //test
	// print_links(ants);  //test
	find_paths(ants->rooms);
}
