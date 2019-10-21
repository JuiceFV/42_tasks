/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 13:33:24 by cspider           #+#    #+#             */
/*   Updated: 2019/10/21 16:37:09 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>

typedef	struct			s_ps_node
{
	int					value;
	struct s_ps_node	*next;
	struct s_ps_node	*prev;
}						t_ps_node;

typedef	struct			s_ps_stack
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

int						create_stack(t_ps_stack *a, t_ps_stack *b,
												char **argv, int argc);
int						stck_append_end(char *str, t_ps_node **back);

/*
**	error detection functions:
**	<is_int> - checks an each argument compliance with the int.
**	<is_dupl> - looking for duplicates
*/

int						is_int(int argc, char **argv);
int						is_dupl(t_ps_stack *a, int argc);

void					push(t_ps_node **from, t_ps_node **to,
													t_ps_node **to_end);
void					swap(t_ps_node **head);
void					rotate(t_ps_node **head, t_ps_node **end);
void					rev_rotate(t_ps_node **head, t_ps_node **end);

long					special_median_a(t_ps_stack *a);
int						deal_higher_a(t_ps_stack *a, char *cmnds, int med,
															int *t_rewind);
void					split_round_median_a(t_ps_stack *a, t_ps_stack *b,
													int med, char *cmnds);
void					three_case(t_ps_stack *a, char *tmp);
void					sort_a(t_ps_stack *a, int count, char *tmp);

t_list					*solver(t_ps_stack *a, t_ps_stack *b);
void					b_to_a(t_ps_stack *a, t_ps_stack *b, t_list **cmnd);
void					push_b(t_ps_stack *b, t_ps_stack *a,
											int count, char *tmp);
int						sorted(t_ps_stack *a);

long					special_median_b(t_ps_stack *b);
int						deal_lower_b(t_ps_stack *b, char *cmnds,
										int med, int count[2]);
void					split_round_median_b(t_ps_stack *a, t_ps_stack *b,
											int med, char *cmnds);
void					three_caseb(t_ps_stack *a, char *tmp);
void					sort_b(t_ps_stack *b, int count, char *tmp);
int						get_count(t_ps_stack *s);
int						get_true_median(t_ps_stack *a);
void					swapper(char *line, t_ps_stack *a, t_ps_stack *b);
void					rotater(char *line, t_ps_stack *a, t_ps_stack *b);
void					rev_rotater(char *line, t_ps_stack *a, t_ps_stack *b);
void					print_res(t_ps_stack *a, t_ps_stack *b, int ok);
int						check_a(t_ps_stack *a);

#endif
