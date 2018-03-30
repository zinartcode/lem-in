/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:50:29 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/29 22:33:28 by azinnatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"
# include <stdlib.h>
# include <stdio.h>
# define SIZE 40
# define RED "\x1B[31m"
# define GRN "\x1B[32m"
# define YEL "\x1B[33m"
# define NRM "\x1B[0m"

struct queue {
    int items[SIZE];
    int front;
    int rear;
}		t_queue;

typedef	struct			s_ants
{
	int					ant_count;
	struct s_room		*rooms;
	struct s_link		*paths;
}						t_ants;

typedef struct			s_link
{
	char				*name;
	int					seen;
	int					donotuse;
	int					shortest;
	int					number_of_ant;
	int					len;
	struct s_link		*path;
	struct s_link		*next;
}						t_link;

typedef	struct			s_room
{
	char				*name;
	int					is_start;
	int					is_end;
	int					position;
	struct s_links		*links;
	int					visited;
	struct s_room		*next;
}						t_room;

void					init(t_ants *ants);
int						read_file(t_ants *ants);
void					ft_solve (t_ants *ants);
void					ft_error(void);
int						is_room(char *line);
void					add_room(t_ants *ants, char *line);