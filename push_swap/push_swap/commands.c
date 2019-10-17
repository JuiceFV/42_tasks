/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cspider <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 16:30:03 by cspider           #+#    #+#             */
/*   Updated: 2019/10/17 17:24:08 by cspider          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_ps_node **from, t_ps_node **to, t_ps_node **to_end)
{
	t_ps_node *tmp;

	if (*from == NULL)
		return ;
	tmp = *from;
	*from = (*from)->next;
	if (*from)
		(*from)->prev = NULL;
	if (*to)
		(*to)->prev = tmp;
	else
		*to_end = tmp;
	tmp->next = *to;
	*to = tmp;
	(*to)->prev = NULL;
}

void	swap(t_ps_node **head)
{
	t_ps_node *tmp;

	if (*head == NULL || (*head)->next == NULL)
		return ;
	tmp = *head;
	*head = (*head)->next;
	tmp->next = (*head)->next;
	tmp->prev = *head;
	(*head)->next = tmp;
	(*head)->prev = NULL;
}

void	rotate(t_ps_node **head, t_ps_node **end)
{
	if (*head == NULL || *end == NULL || (*head)->next == NULL)
		return ;
	(*end)->next = *head;
	(*head)->prev = *end;
	*head = (*head)->next;
	(*head)->prev = NULL;
	*end = (*end)->next;
	(*end)->next = NULL;
}

void	rev_rotate(t_ps_node **head, t_ps_node **end)
{
	if (*head == NULL || *end == NULL || (*end)->prev == NULL)
		return ;
	(*head)->prev = *end;
	(*end)->next = *head;
	*head = *end;
	*end = (*end)->prev;
	(*end)->next = NULL;
	(*head)->prev = NULL;
}
