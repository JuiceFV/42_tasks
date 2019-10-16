#include "push_swap.h"
/*
** Didn't check
** specific case with an arg == 00000000...0<number>
*/
static int true_int(char *argv)
{
	const int num = ft_atoi(argv);
	if (num == 0 || num == -1)
	{
		if (argv[0] == '-' || argv[0] == '+')
		{
			if (num == 0 && argv[1] != '0')
				return (0);
			else if (num == -1 && argv[1] != '1')
				return (0);
		}
		else
			if (num == 0 && argv[0] != '0')
				return (0);
	}
	return (1);
}
int	is_int(int argc, char **argv)
{
	int i;
	int j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '-')
			j++;
		if (!ft_isdigit(argv[i][j]))
			return (0);
		while (ft_isdigit(argv[i][j]))
			j++;
		if (argv[i][j])
			return (0);
		if (!true_int(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

int is_dupl(t_ps_stack *a, int argc)
{
	t_ps_node *tmp;
	int		i;
	int		j;
	int		k;
	int		arr[argc + 1];

	tmp = a->begin;
	i = 0;
	while (tmp)
	{
		arr[i++] = tmp->value;
		tmp = tmp->next;
	}
	j = -1;
	while (j++ < i)
	{
		k = j;
		while (++k < i)
			if (arr[j] == arr[k])
				return (0);
	}
	return (1);
}