#include "push_swap.h"
int stck_append_end(char *str, t_ps_node **back)
{
	t_ps_node 	*tmp;
	int 		num;

	num = ft_atoi(str);
	if (*back == NULL)
		return (-1);
	if(!(tmp = (t_ps_node *)malloc(sizeof(t_ps_node))))
		return (-1);
	tmp->value = num;
	tmp->next = NULL;
	(*back)->next = tmp;
	tmp->prev = *back;
	*back = tmp;
}
int	create_stack(t_ps_stack *a, t_ps_stack *b, char **argv, int argc)
{
	int 		i;
	t_ps_node	*tmp;

	i = 1;
	if (!is_int(argc, argv) || !(a->begin = (t_ps_node *)malloc(sizeof(t_ps_node))))
		return (-1);
	a->begin->value = ft_atoi(argv[i]);
	a->begin->prev = NULL;
	a->end = a->begin;
	while (i < ac)
		stck_append_end(argv[i++], &a->end);
	if (!is_dupl(a, argc))
	{
		while (a->begin)
		{
			tmp = a->begin;
			a->begin = a->begin->next;
			free(tmp);
		}
		return (-1);
	}
	b->begin = NULL;
	b->end = NULL;
	return (1);
}