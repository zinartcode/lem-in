/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/17 21:42:38 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/17 21:43:42 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int		is_room(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (0);
	else if ((ft_space(line)) == 2)
		return (1);
	return (0);
}

int		is_comment(char *line)
{
	if (line[0] == '#' || line[0] == 'L')
		return (1);
	else
		return (0);
}

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