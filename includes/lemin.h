/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:50:29 by azinnatu          #+#    #+#             */
/*   Updated: 2018/03/31 01:53:55 by azinnatu         ###   ########.fr       */
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
	int					room_count;
	int					flag;
	struct s_room		*rooms;
	struct s_link		*paths;
}						t_ants;

typedef	struct			s_room
{
	char				*name;
	int					is_start;
	int					is_end;
	int					number_of_ant;
	int					position;
	int					visited;
	struct s_link		*links;
	struct s_room		*next;
}						t_room;

typedef struct			s_link
{
	char				*name1;
	char				*name2;
	int					seen;
	int					is_path;
	int					shortest;
	int					len;
	struct s_link		*path;
	struct s_link		*next;
}						t_link;

void					init(t_ants *ants);
void					init_room(t_room *room);
void					init_link(t_link *link);
int						read_file(t_ants *ants);
void					ft_solve (t_ants *ants);
void					ft_error(void);
int						is_room(char *line);
int						is_link(char *line);
int						valid_link(t_ants *ants, char *line);
int						is_comment(char *line);
void					add_room(t_ants *ants, char *line);
void					add_link(t_ants *ants, char *line);

void					print_rooms(t_ants *ants);
void					print_links(t_ants *ants);
