/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 22:10:54 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/17 22:14:00 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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

void	print_short(t_room **room, int i)
{
	int	n;
	n = 1;
	while (n <= i)
	{
		print_ant(n, room[1]->name);
		ft_putchar('\n');
		n++;
	}
}

void	print_ant(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}