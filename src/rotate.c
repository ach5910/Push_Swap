/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:42:54 by ahunt             #+#    #+#             */
/*   Updated: 2017/02/21 18:43:07 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void ft_rotate(t_list **stack)
{
	t_list *temp;
	t_list *head;
	int	*data;
	if (!*stack)
		return ;
	temp = *stack;
	head = *stack;
	//data = (*stack)->content;
	*stack = temp->next;
	while (temp->next)
		temp = temp->next;
	temp->next = head;
	head->next = NULL;
}
void ft_rev_rotate(t_list **stack)
{
	t_list *head;
	t_list *cur;
	t_list *prev;

	head = *stack;
	prev = head;
	cur = head->next;
	while (cur->next)
	{
		prev = cur;
		cur = cur->next;
	}
	prev->next = NULL;
	cur->next = head;
	*stack = cur;
}
