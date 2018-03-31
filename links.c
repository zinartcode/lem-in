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
		ft_printf("this is valid link: %s\n", line);
	else
		ft_error();
}

int			valid_link(t_ants *ants, char *line)
{
	t_room	*temp;
	char	*link[3];
	int		i;
	int		flag;

	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	link[0] = ft_strndup(line, i);
	link[1] = "-";
	i++;
	link[2] = ft_strdup(&line[i++]);
	if (ft_strcmp(link[0],link[2]) == 0)
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
		if (ft_strcmp(temp->name, link[2]) == 0)
			return (1);
		temp = temp->next;
	}
	return (0);
}
