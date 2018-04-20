/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:10:23 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/19 18:39:32 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	ft_solve(ants);
	move_ants(ants);
	return (0);
}

int			read_file(t_ants *ants)
{
	char	*line;
	int		i;

	i = 0;
	get_next_line(0, &line);
	ft_printf("%s\n", line);
	free(line);
	ants->ant_count = ft_atoi(line);
	if (ants->ant_count <= 0 || ants->ant_count > 2147483647)
		ft_error();
	while (get_next_line(0, &line))
	{
		parse_file(ants, line);
		free(line);
	}
	if (ants->start_end != 2)
		ft_error();
	ft_putchar('\n');
	if (line)
		free(line);
	return (0);
}

void		parse_file(t_ants *ants, char *line)
{
	ft_printf("%s\n", line);
	if (!ft_strcmp("##start", line))
	{
		ants->flag = 1;
		ants->start_end++;
	}
	else if (!ft_strcmp("##end", line))
	{
		ants->flag = 2;
		ants->start_end++;
	}
	if (is_room(line))
	{
		ants->room_count++;
		add_room(ants, line);
		ants->flag = 0;
	}
	else if (is_link(line))
		add_link(ants, line);
	else if (is_comment(line))
		;
	else
		ft_error();
}

void		ft_error(void)
{
	ft_putstr_fd(RED"Error\n"NRM, 2);
	exit(0);
}
