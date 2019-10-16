#include "push_swap.h"

int main()
{
	t_ps_stack	a;
	t_ps_stack	b;
	t_list		*opt;

	if (!create_stack(&a, &b, argv, argc))
	{
		ft_dprintf(2, "Error\n");
		return (-1);
	}
}