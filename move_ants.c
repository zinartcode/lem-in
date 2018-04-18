/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 00:16:41 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/18 00:31:23 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	move_ants(t_ants *ants)
{
	t_room	**my_path;
	int		i;
	int		ant;
	int 	j;
	int		last;

	i = 0;
	last = 0;
	j = 1;
	ant = 1;
	my_path = ants->paths;
	while (my_path[last]->is_end != 1)
		last++;
	if (last <= 1)
	{
		print_short(my_path, ants->ant_count);
		return ;
	}
	my_path[1]->number_of_ant = 1;
	while (my_path[last]->number_of_ant < ants->ant_count)
	{
		print_moves(my_path, last);
		check_ants(my_path, last, ants->ant_count);
	}
	if (my_path[1]->number_of_ant != 0)
		my_path[1]->number_of_ant = 0;
		print_moves(my_path, last);
}

void		check_ants(t_room **room, int i, int ant)
{
	t_room **my_path;

	my_path = room;
	int	n;
	int	temp;
	int	j;

	j = 0;
	n = i;
	temp = 0;
	while (my_path[n]->number_of_ant == 0)
		n--;
	while (n > 0)
	{
		j = n + 1;
		temp = my_path[n]->number_of_ant;
		if (my_path[j])
		{
			my_path[j]->number_of_ant = temp;
			my_path[n]->number_of_ant = temp + 1;
		}
		n--;
	}
	check_ants_2(my_path, i, ant);
}

void		check_ants_2(t_room **room, int i, int ant)
{
	int		n;

	n = 1;
	if (room[i]->number_of_ant != 0)
	{
		if (room[1]->number_of_ant == 1)
			room[1]->number_of_ant = 0;
	}
	while (n <= i)
	{
		if (room[n]->number_of_ant > ant)
			room[n]->number_of_ant = 0;
		n++;
	}
}
