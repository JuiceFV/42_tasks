#include "push_swap.h"

int	create_stack(t_ps_stack *a, t_ps_stack *b, char **argv, int argc)
{
	int 		i;
	t_ps_node	*tmp;

	i = 1;
	a->begin->value = ft_atoi(argv[i]);
	if ((a->begin->value == 0 && !is_int(argc, argv)) ||
		!(a->begin = (t_ps_node *)malloc(sizeof(t_ps_node))))
}