/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:10:23 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/30 01:03:06 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lemin.h"

int			main(void)
{
	t_ants	*ants;

	ants = malloc(sizeof(t_ants));
	init(ants);
	if (read_file(ants) == 1)
	{
		ft_error();
		return (0);
	}
	print_rooms(ants);
	ft_solve(ants);
	return (0);
}

int		read_file(t_ants *ants)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	ants->ant_count = ft_atoi(line);
	if (ants->ant_count <= 0 || ants->ant_count > 2147483647)
		ft_error();
	ft_putnbr(ants->ant_count);
	ft_putchar('\n');
	while (get_next_line(0, &line))
	{
		if (is_room(line))
			add_room(ants, line);
		else if (is_link(line))
			add_link(ants, line);
		else if (is_comment(line))
			;
		else
			ft_error();
	}
	return (0);
}

void	ft_error(void)
{
	ft_putstr_fd(RED"Error\n"NRM, 2);
	exit(0);
}

void	init(t_ants *ants)
{
	ants->ant_count = 0;
	ants->rooms = NULL;
	ants->paths = NULL;
}

void	init_room(t_room *room)
{
	room->name = NULL;
	room->is_start = 0;
	room->is_end = 0;
	room->position = 0;
	room->visited = 0;
	room->links = NULL;
	room->next = NULL;
}

void	init_link(t_link *link)
{
	link->name = NULL;
	link->seen = 0;
	link->is_path = 0;
	link->shortest = 0;
	link->number_of_ant = 0;
	link->len = 0;
	link->path = NULL;
	link->next = NULL;
}