/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 23:05:22 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/12 00:11:22 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		find_paths(t_ants *ants, t_room *root)
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
	find_paths_2(ants, root, ptr);
}

void	find_paths_2(t_ants *ants, t_room *root, t_room *ptr)
{
	int	i;

	clean_rooms(all_rooms);
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
	store_path(ants, ptr);
}

void			store_path(t_ants *ants, t_room *room)
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
	i = 0;
	ptr = finish;
	while (ptr != start)
	{
		ptr = ptr->prev;
		i++;
		if (ptr == NULL)
			break ;
	}
	ptr = finish;
	store_path_2(ants, ptr, i);
}

void	store_path_2(t_ants *ants, t_room *room, int i)
{
	t_room		**temp;
	t_room		*ptr;

	ptr = room;
	temp = ft_memalloc((i + 1) * sizeof(struct s_room *));
	while (ptr->is_start != 1)
	{
		temp[i] = ptr;
		ptr = ptr->prev;
		i--;
		if (ptr == NULL)
			break ;
	}
	temp[i] = ptr;
	ants->paths = temp;
	i = 0;
	// while (temp[i] != NULL)
	// {
	// 	printf("%s\n", temp[i]->name);
	// 	i++;
	// }
	return ;	
}