/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:34:26 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/30 23:14:01 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

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
	t_ants	*temp;
	t_ants	*temp2;
	char	*link[3];
	int		i;
	int		flag;

	// temp = (t_ants*)malloc(sizeof(t_ants));
	// temp2 = (t_ants*)malloc(sizeof(t_ants));
	temp = ants;
	temp2 = ants;
	flag = 0;
	i = 0;
	while (line[i] && line[i] != '-')
		i++;
	link[0] = ft_strndup(line, i);
	link[1] = "-";
	i++;
	link[2] = ft_strdup(&line[i++]);
	if (link[0] == link[2])
		return (0);
	ft_printf("I'm here\n");
	ft_printf("%s\n", temp->rooms->name);
	while (temp->rooms != NULL)
	{
		if (ft_strcmp(temp->rooms->name, link[0]))
			flag = 1;
		temp->rooms = temp->rooms->next;
		ft_printf("%s\n", temp->rooms->name);
	}
	if (flag == 0)
		return (0);
	while (temp2->rooms != NULL)
	{
		if (ft_strcmp(temp->rooms->name, link[2]))
			flag = 1;
		temp->rooms = temp->rooms->next;
	}
	if (flag == 0)
		return (0);
	// ft_printf("array has: %s, %s, %s, ", link[0], link[1], link[2]);
	return (1);
}