/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:06:14 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 22:22:04 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/lemin.h"

int	is_room(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	else if ((ft_space(line)) == 2)
		return (1);
	return (0);
}

void	add_room(t_ants *ants, char *line)
{
	ft_printf("this is room: %s\n", line);
}