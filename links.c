/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:34:26 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/17 21:47:26 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void		add_link(t_ants *ants, char *line)
{
	if (valid_link(ants, line) == 1)
	{
		char **link;
		t_room *temp;
		t_link *new;

		link = ft_strsplit(line, '-');
		temp = ants->rooms;
		while (temp)
		{
			new = create_link(ants, link, temp);
			temp = temp->next;
		}
		free(link[0]);
		free(link[1]);
	}
	else
		ft_error();
}

t_link		*create_link(t_ants *ants, char **link, t_room *temp)
{
	t_link	*new;

	new = NULL;
	if (ft_strcmp(link[0], temp->name) == 0)
	{
		new = (t_link *)malloc(sizeof(t_link));
		init_link(new);
		new->name1 = ft_strdup(link[0]);
		new->name2 = ft_strdup(link[1]);
		new->parent = find_room(ants->rooms, link[1]);
		link_to_room(temp, new);
	}
	else if (ft_strcmp(link[1], temp->name) == 0)
	{
		new = (t_link *)malloc(sizeof(t_link));
		init_link(new);
		new->name1 = ft_strdup(link[1]);
		new->name2 = ft_strdup(link[0]);
		new->parent = find_room(ants->rooms, link[0]);
		link_to_room(temp, new);
	}
	return (new);
}

int		same_link(t_room *room, t_link *new)
{
	t_link	*temp;
	int		room1;
	int		room2;

	temp = room->links;

	while (temp && new)
	{
		room1 = 0;
		room2 = 0;
		if (ft_strcmp(new->name1, temp->name1) == 0)
			room1 = 1;
		if (ft_strcmp(new->name2, temp->name2) == 0)
			room2 = 1;
		if (room1 == 1 && room2 == 1)
		return (1);
		temp = temp->next;
	}
	return (0);
}

int			valid_link(t_ants *ants, char *line)
{
	t_room	*temp;
	char	*link[2];
	int		i;
	int		flag;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	link[0] = ft_strndup(line, i);
	i++;
	link[1] = ft_strdup(&line[i++]);
	if (ft_strcmp(link[0],link[1]) == 0)
		return (0);
	temp = ants->rooms;
	flag = 0;
	if (valid_link_2(ants, temp, link))
		return (1);
	return (0);
}

int			valid_link_2(t_ants *ants, t_room *room, char **link)
{
	int		flag;
	t_room	*temp;

	flag = 0;
	temp = room;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->name, link[0]) == 0)
		{
			flag = 1;
			break;
		}
		temp = temp->next;
	}
	if (flag == 0)
		return (0);
	temp = ants->rooms;
	while (temp != NULL)
	{
		if (ft_strcmp(temp->name, link[1]) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}
