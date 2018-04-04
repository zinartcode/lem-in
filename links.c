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

// void		add_link(t_ants *ants, char *line)
// {
// 	if (valid_link(ants, line) == 1)
// 	{
// 		char **link;
// 		t_room *temp;
// 		t_link *new;
// 		char matrix[ants->room_count][ants->room_count];

// 		link = ft_strsplit(line, '-');
// 		temp = ants->rooms;
// 		while (temp->next != NULL)
// 		{
// 			if (ft_strcmp(link[0], temp->name) == 0)
// 			{
// 				new = (t_link *)malloc(sizeof(t_link));
// 				new->name1 = ft_strdup(link[0]);
// 				new->name2 = ft_strdup(link[1]);
// 			}
// 			temp = temp->next;
// 		}
// 		ft_printf("this is valid link: %s, %s\n", link[0], link[1]);
// 	}
// 	else
// 		ft_error();
// }

void		add_link(t_ants *ants, char *line)
{
	if (valid_link(ants, line) == 1)
	{
		char **link;
		t_room *temp;
		t_link *new;
		char matrix[ants->room_count][ants->room_count];

		link = ft_strsplit(line, '-');
		temp = ants->rooms;
		while (temp->next != NULL)
		{
			if (ft_strcmp(link[0], temp->name) == 0)
			{
				matrix[temp->position][]
			}
			temp = temp->next;
		}
		ft_printf("this is valid link: %s, %s\n", link[0], link[1]);
	}
	else
		ft_error();
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
	struct s_link	*temp;

	temp = ants->rooms->links;
	while (temp != NULL)
	{
		while (temp != NULL)
		{
			ft_printf("Link is: %s, %s\n", temp->name1, temp->name2);
			temp = temp->next;
		}
	}
}

