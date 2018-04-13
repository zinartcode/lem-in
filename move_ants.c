/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 00:16:41 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/12 23:16:38 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	move_ants(t_ants *ants)
{
	t_room	**my_path;
	int		i;

	i = 0;
	my_path = ants->paths;
	ft_printf("We have %d ants\n", ants->ant_count);
	while (my_path[i] != NULL)
	{
		ft_printf("Room: %s,  ant: %d\n", my_path[i]->name, my_path[i]->number_of_ant);
		// my_path = my_path->next;
		i++;
	}

}