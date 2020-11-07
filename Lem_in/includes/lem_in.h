/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olongbot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 16:03:13 by olongbot          #+#    #+#             */
/*   Updated: 2020/10/15 14:08:14 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H

# define LEM_IN_H

# include "libft.h"

# define FT_UINT_MAX	((unsigned)(~0L))
# define FT_INT_MAX		((int)(FT_UINT_MAX >> 1))

typedef struct			s_line
{
	char				*content;
	struct s_line		*next;
}						t_line;

typedef enum
{
	START,
	MIDDLE,
	END
}	t_type;

typedef struct			s_room
{
	char				*name;
	int					x;
	int					y;
	t_type				type;
	int					bfs_level;
	int					input_links;
	int					output_links;
	int					ant_number;
	struct s_room		*next;
}						t_room;

typedef struct			s_link
{
	t_room				*start;
	t_room				*end;
	struct s_link		*next;
	struct s_link		*prev;
}						t_link;

typedef struct			s_path
{
	t_link				*head;
	int					length;
	struct s_path		*next;
}						t_path;

typedef struct			s_location
{
	int					ant_number;
	t_room				*room;
	struct s_location	*next;
}						t_location;

typedef struct			s_turn
{
	t_location			*locations;
	struct s_turn		*next;
}						t_turn;

typedef struct			s_lem_in
{
	int					ants_start;
	int					ants_end;
	int					ant_number;
	t_room				*rooms;
	t_room				*start;
	t_room				*end;
	t_link				*links;
	int					bfs_level;
	t_path				*paths;
	t_location			*locations;
	t_turn				*turns;
}						t_lem_in;

typedef struct			s_queue
{
	t_room				*room;
	struct s_queue		*next;
}						t_queue;

t_line					*read_next_line(t_line **lines);
t_lem_in				*parse(t_line **lines);
void					parse_ants(t_lem_in *lem_in, t_line **current,
							t_line **lines);
void					parse_rooms(t_lem_in *lem_in, t_line **current,
							t_line **lines);
void					parse_links(t_lem_in *lem_in, t_line **current,
							t_line **lines);
void					validate_room(t_lem_in *lem_in, t_room *room);
void					validate_link(t_lem_in *lem_in, t_link *link);
int						is_command(char *str);
int						is_comment(char *str);
int						is_room(char *str);
void					swap_rooms(t_room **start, t_room **end);
void					bfs(t_lem_in *lem_in);
void					align_links(t_lem_in *lem_in);
void					count_io_links(t_lem_in *lem_in);
t_room					*find_room(t_lem_in *lem_in, char *name);
t_link					*find_link(t_lem_in	*lem_in, t_room *start,
							t_room *end);
void					delete_useless_links(t_lem_in *lem_in);
void					delete_dead_ends(t_lem_in *lem_in);
void					delete_link(t_lem_in *lem_in, t_link *link);
t_link					*remove_link(t_lem_in *lem_in, t_link *link);
void					delete_input_forks(t_lem_in *lem_in);
void					delete_output_forks(t_lem_in *lem_in);
void					form_paths(t_lem_in *lem_in);
t_location				*turn_create_location(int ant_number, t_room *room);
void					turn_add_location(t_lem_in *lem_in,
						t_location *location);
void					perform_turns(t_lem_in *lem_in);
void					lines_free(t_line **lines);
void					lem_in_free(t_lem_in **lem_in);
void					turns_free(t_turn **current);
void					locations_free(t_location **current);
void					paths_free(t_path **current);
void					links_free(t_link **current);
void					rooms_free(t_room **current);
void					terminate(char *s);
void					print_locations(t_lem_in *lem_in);
int						ft_isint(const char *str, int strict);
void					ft_strsplit_free(char ***strsplit);
size_t					ft_strsplit_len(char **strsplit);

#endif
