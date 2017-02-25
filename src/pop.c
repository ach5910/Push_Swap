/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:45:58 by ahunt             #+#    #+#             */
/*   Updated: 2017/02/21 18:46:16 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

t_list *ft_pop(t_list **stack)
{
	t_list *data;
	t_list temp;

	if (!(*stack))
		return (NULL);
	data = (*stack);
	if ((*stack)->next)
		(*stack) = (*stack)->next;
	else
		(*stack) = NULL;
	return (data);
}

void ft_pop_push(t_list **pop, t_list **push)
{
	ft_lstadd(push, ft_pop(pop));
}
