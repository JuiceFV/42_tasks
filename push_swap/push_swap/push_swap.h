#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef	struct 			s_ps_node
{
	int					value;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
}						t_ps_node;

typedef struct 			s_ps_stack
{
	t_ps_node			*begin;
	t_ps_node			*end;
	t_ps_node			**els;
	int					top;
	int					argc;
}						t_ps_stack;

/*
** stack operations:
*/

int	create_stack(t_ps_stack *a, t_ps_stack *b, char **argv, int argc);
int stck_append_end(char *str, t_ps_node **back);

/*
**	error detection functions:
**	<is_int> - checks an each argument compliance with the int.
**	<is_dupl> - looking for duplicates 
*/

int	is_int(int argc, char **argv);
int is_dupl(t_ps_stack *a, int argc);
#endif