/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azinnatu <azinnatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 19:50:29 by azinnatu          #+#    #+#             */
/*   Updated: 2018/04/18 00:17:11 by azinnatu         ###   ########.fr       */
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

typedef struct			s_link
{
	char				*name1;
	char				*name2;
	int					seen;
	int					is_path;
	int					shortest;
	int					len;
	struct s_room		*parent;
	struct s_link		*path;
	struct s_link		*next;
}						t_link;

typedef	struct			s_room
{
	char				*name;
	int					is_start;
	int					is_end;
	int					number_of_ant;
	int					position;
	int					visited;
	int					in_queue;
	t_link				*links;
	struct s_room		**nodes;
	struct s_room		*prev;
	struct s_room		*next;
}						t_room;

struct	s_room	**all_rooms;

typedef	struct			s_ants
{
	int					ant_count;
	int					room_count;
	int					flag;
	int					start_end;
	t_room				*rooms;
	t_room				**paths;
	t_link				*temp_path;
}						t_ants;

void					init(t_ants *ants);
void					init_room(t_room *room);
void					init_link(t_link *link);
void					free_all(t_ants *ants);
void					free_array(char **arr);
void					free_rooms(t_room *rooms);
void					delete_links(t_link *links);
int						read_file(t_ants *ants);
void					ft_solve (t_ants *ants);
void					parse_file(t_ants *ants, char *line);
void					find_path(t_room *root);
void					ft_error(void);
int						is_room(char *line);
int						is_link(char *line);
int						count_links(t_room *room);
int						valid_link(t_ants *ants, char *line);
int						valid_link_2(t_ants *ants, t_room *room, char **link);
int						is_comment(char *line);
void					add_room(t_ants *ants, char *line);
void					add_link(t_ants *ants, char *line);
void					create_links(t_room *room);
int						same_link(t_room *room, t_link *new);
void					link_to_room(t_room *temp, t_link *new);

t_room					*find_room(t_room *room, char *name);
t_room					*last_room(t_room *room);
t_room					*start_move(t_room *room);
t_room					*end_move(t_room *room);
t_link					*create_link(t_ants *ants, char **link, t_room *temp);

void					clean_rooms(t_room	**all_rooms);
void					find_paths(t_ants *ants, t_room *root);
void					find_paths_2(t_ants *ants, t_room *root, t_room *ptr);
void					store_path(t_ants *ants, t_room *room, int i);
void					store_path_2(t_ants *ants, t_room *room, int i);

void					move_ants(t_ants *ants);
void					check_ants(t_room **room, int i, int ant);
void					check_ants_2(t_room **room, int i, int ant);
void					print_moves(t_room **room, int i);
void					print_ant(int ant, char *room);
void					print_short(t_room **room, int i);
