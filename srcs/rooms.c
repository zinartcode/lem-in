/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:06:14 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/30 01:00:36 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lemin.h"

int		is_room(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	else if ((ft_space(line)) == 2)
		return (1);
	return (0);
}

void	add_room(t_ants *ants, char *line)
{
	int			i;
	t_room		*new;
	t_ants		*temp;

	i = 0;
	temp = ants;
	new = (t_room *)malloc(sizeof(t_room));
	init_room(new);
	while (line[i] != ' ')
		i++;
	new->name = ft_strndup(line, i);
	if (temp->rooms == NULL)
		temp->rooms = new;
	else
	{
		while (temp->rooms != NULL)
			temp->rooms = temp->rooms->next;
		temp->rooms = new;
	}
	print_rooms(ants);
	// ft_printf ("oh room name is %s\n", new->name);

}

int		is_comment(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (1);
	else
		return (0);
}


void	print_rooms(t_ants *ants)
{
	t_ants		*temp;
	temp = ants;
	while (temp->rooms != NULL)
	{
		ft_printf("here is the room: %s\n", temp->rooms->name);
		temp->rooms = temp->rooms->next;
	}
}