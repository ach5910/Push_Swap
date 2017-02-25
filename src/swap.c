/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:44:59 by ahunt             #+#    #+#             */
/*   Updated: 2017/02/21 18:45:15 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void ft_swap(t_list **stack)
{
	t_list *head;
	t_list *temp;
	t_list *second;

	if (ft_lstcount(*stack) < 2)
		return ;
	head = *stack;
	second = head->next;
	temp = second->next;
	second->next = head;
	head->next = temp;
	*stack = second;
}
