/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 21:35:10 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/17 21:43:55 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	find_paths(ants, ants->rooms);
}
