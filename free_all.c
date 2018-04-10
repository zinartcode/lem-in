/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 18:39:25 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/09 20:16:01 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	free_all(t_ants *ants)
{
	if (ants->rooms)
		free_rooms(ants->rooms);
	// if (lemin->rooms)
	// 	delete_path(lemin);
	// ft_strdel(&lemin->input);
	ft_memdel((void*)&ants);	
}

void	free_rooms(t_room *rooms)
{
	while (rooms)
	{
		while (rooms->links)
		{
			delete_links(rooms->links);
			ft_memdel((void*)&rooms->name);
			free(rooms->name);
			// rooms->links = rooms->links->next;
		}
		rooms = rooms->next;
	}
}

void	delete_links(t_link *links)
{
	while (links)
	{
		ft_memdel((void*)&links->name1);
		ft_memdel((void*)&links->name2);
		free(links);
		links = links->next;
	}
}