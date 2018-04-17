/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 00:16:41 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/12 23:59:04 by azinnatu         ###   ########.fr       */
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
	n = 1;
	while (n <= i)
	{
		if (my_path[n]->number_of_ant > ant)
			my_path[n]->number_of_ant = 0;
		n++;
	}
}

void	print_moves(t_room **room, int i)
{
	while (room[i]->number_of_ant == 0)
		i--;
	while (room[i]->is_start != 1 || room[i]->number_of_ant != 0)
	{
		if (room[i]->number_of_ant != 0)
			print_ant(room[i]->number_of_ant, room[i]->name);
		i--;
	}
	ft_putchar('\n');
}

void	print_ant(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}