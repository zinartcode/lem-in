/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:34:26 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/31 02:03:46 by azinnatu         ###   ########.fr       */
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
		// char matrix[ants->room_count][ants->room_count];

		link = ft_strsplit(line, '-');
		temp = ants->rooms;
		while (temp)
		{
			if (ft_strcmp(link[0], temp->name) == 0)
			{
				new = (t_link *)malloc(sizeof(t_link));
				new->name1 = ft_strdup(link[0]);
				new->name2 = ft_strdup(link[1]);
				link_to_room(ants, new);
			}
			temp = temp->next;
		}
		// ft_printf("this is valid link: %s, %s\n", link[0], link[1]);
	}
	else
		ft_error();
}

void	link_to_room(t_ants *ants, t_link *new)
{
	t_link	*add;
	if (ants->rooms->links == NULL)
		ants->rooms->links = new;
	else if (same_link(ants, new) != 1)
	{
		add = ants->rooms->links;
		while (add->next != NULL)
			add = add->next;
		add->next = new;
	}
	else
		ft_error();
}

int		same_link(t_ants *ants, t_link *new)
{
	t_link	*temp;
	int		room1;
	int		room2;

	temp = ants->rooms->links;
	while (temp)
	{
		room1 = 0;
		room2 = 0;
		// ft_printf("in new: %s, %s\n", new->name1, new->name2);
		// ft_printf("in same link: %s, %s\n", temp->name1, temp->name2);
		if (ft_strcmp(new->name1, temp->name1) == 0 || ft_strcmp(new->name1, temp->name2) == 0)
			room1 = 1;
		if (ft_strcmp(new->name2, temp->name2) == 0 || ft_strcmp(new->name2, temp->name1) == 0)
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

	temp = ants->rooms->links;
	temp_room = ants->rooms;
	while (temp_room != NULL)
	{
		ft_printf("I'm in room %s\n", temp_room->name);
		while (temp != NULL)
		{
			ft_printf("Link is: %s, %s\n", temp->name1, temp->name2);
			temp = temp->next;
		}
		temp_room = temp_room->next;
	}
}

