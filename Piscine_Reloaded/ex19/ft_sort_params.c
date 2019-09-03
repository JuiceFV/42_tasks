/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 21:44:24 by cspider           #+#    #+#             */
/*   Updated: 2019/09/02 21:44:45 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_putchar(char c);

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str++;
	}
	ft_putchar('\n');
}

int		compare(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	swap(int *index1, int *index2)
{
	int tmp;

	tmp = *index1;
	*index1 = *index2;
	*index2 = tmp;
}

void	print_arg(char **argv_arg, int len, int *i_array)
{
	int i;

	i = 1;
	while (i < len)
	{
		ft_putstr(argv_arg[i_array[i]]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int i;
	int j;
	int arr[argc];

	i = 1;
	while (i < argc)
	{
		arr[i] = i;
		i++;
	}
	i = 1;
	while (i < argc)
	{
		j = i;
		while (j < argc)
		{
			if (compare(argv[arr[i]], argv[arr[j]]) > 0)
				swap(&arr[i], &arr[j]);
			j++;
		}
		i++;
	}
	print_arg(argv, argc, arr);
	return (0);
}
