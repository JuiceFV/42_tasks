#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef	struct 			s_ps_node
{
	int					key;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
}						t_ps_node;

typedef struct 			s_ps_stack
{
	t_ps_node			*begin;
	t_ps_node			*end;
	t_ps_node			**p;
	int					top;
	int					argc;
}						t_ps_stack;


#endif