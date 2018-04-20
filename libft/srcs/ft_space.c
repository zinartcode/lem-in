/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 22:20:39 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/18 02:40:05 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_space(char *str)
{
	int	space;
	int	i;

	space = 0;
	i = -1;
	while (str[++i])
	{
		if (str[i] == ' ')
			space++;
	}
	return (space);
}
