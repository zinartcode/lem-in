/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:34:26 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/10 20:58:35 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			is_link(char *line)
{
	int		i;
	int		dash;
	int		k;

	i = 0;
	dash = 0;
	k = 0;
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\t')
			ft_error();
		if (line[i] != '-')
			k++;
		else if (k != 0 && line[i] == '-')
		{
			dash++;
			k = 0;
		}
		i++;
	}
	if (k != 0 && dash == 1)
		return (1);
	return (0);
}

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
			temp = temp->next;
		}
		free(link[0]);
		free(link[1]);
	}
	else
		ft_error();
}

void	link_to_room(t_room *temp, t_link *new)
{
	t_link	*add;

	if (temp->links == NULL)
		temp->links = new;
	else if (same_link(temp, new) != 1)
	{
		add = temp->links;
		while (add->next != NULL)
			add = add->next;
		add->next = new;
	}
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

void	print_links(t_ants *ants)
{
	t_link	*temp;
	t_room	*temp_room;

	temp_room = ants->rooms;
	while (temp_room != NULL)
	{
		temp = temp_room->links;
		ft_printf(RED"I'm in room %s\n"NRM, temp_room->name);
		while (temp != NULL)
		{
			ft_printf("Path to room: %s\n", temp->parent->name);
			temp = temp->next;
		}
		temp_room = temp_room->next;
	}
}

