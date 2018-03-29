/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:10:23 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/28 21:47:29 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/lemin.h"

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
	return (0);
}

void	init(t_ants *ants)
{
	ants->ant_count = 0;
	ants->rooms = NULL;
	ants->paths = NULL;
}

int		read_file(t_ants *ants)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(i, &line))
	{
		ft_putstr(line);
		ft_putchar('\n');
	}
	return (0);
}

void	ft_error(void)
{
	ft_putstr("ERROR");
}
