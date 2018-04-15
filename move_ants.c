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
	// t_room	*finish;
	int		i;
	int		ant;
	int 	j;
	int		last;

	i = 0;
	last = 0;
	j = 1;
	ant = 1;
	my_path = ants->paths;
	while (my_path[i] != NULL)
	{
		printf("%s\n", my_path[i]->name);
		i++;
	}
	while (my_path[last]->is_end != 1)
		last++;
	printf("Number of ants: %d\n", ants->ant_count);
	printf("last one: %s\n", my_path[last]->name);
	printf("first one: %s\n", my_path[j]->name);

	my_path[1]->number_of_ant = 1;
	print_moves(my_path, last);

	my_path[1]->number_of_ant = 2;
	my_path[2]->number_of_ant = 1;
	print_moves(my_path, last);

	my_path[1]->number_of_ant = 3;
	my_path[2]->number_of_ant = 2;
	my_path[3]->number_of_ant = 1;
	print_moves(my_path, last);

}

void	check_ants(t_room *room, int i)
{
	// t_room **my_path;

	// my_path = ants->paths;
	while (room[i].is_start != 1)
	{
		// printf("This is room: %s, ants: %d\n", room[i]->name, room[i]->number_of_ant);
		// printf("Prev room: %s\n", room[i]->prev->name);
		room[i].number_of_ant = room[i].prev->number_of_ant;
		i--;
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