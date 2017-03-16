/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:47:15 by ahunt             #+#    #+#             */
/*   Updated: 2017/02/21 18:47:26 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

int	ft_lstcount(t_list *list)
{
	if (list->next == NULL)
		return (1);
	return (1 + ft_lstcount(list->next));
}

void ft_listaddback(t_list **stack, t_list *elem)
{
	t_list *node;

	if (!*stack)
	{
		ft_lstadd(stack, elem);
		return ;
	}
	node = *stack;
	while (node->next)
		node = node->next;
	node->next = elem;
}

int ft_is_rev_sorted(t_list **stack_a)
{
	t_list *a;
	int *prev_val;
	int *curr_val;

	if (!*stack_a)
		return (-1);
	a = *stack_a;
	prev_val = a->content;
	a = a->next;
	while (a)
	{
		curr_val = a->content;
		if (*prev_val <= *curr_val)
		{
			if (*prev_val == *curr_val)
				return (-1);
			return (0);
		}
		a = a->next;
		prev_val = curr_val;
	}
	return (1);
}
// int ft_is_loopsorted(t_data *list_data)
// {
// 	t_list *a;
// 	int *prev_val;
// 	int *curr_val;

// 	if (!(list_data->stack_a))
// 		return (-1);
// 	a = list_data->stack_a;
// 	prev_val = a->content;
// 	a = a->next;
// 	ft_get_limits(list_data);
// 	while (a)
// 	{
// 		curr_val = a->content;
// 		if (*prev_val >= *curr_val)
// 		{
// 			if (*prev_val == *curr_val)
// 				return (-1);
// 			else if (*prev_val != list_data->max && *curr_val != list_data->min)
// 				return (0);
// 		}
// 		a = a->next;
// 		prev_val = curr_val;
// 	}
// 	return (1);
// }
int ft_is_sorted(t_list **stack_a)
{
	t_list *a;
	int *prev_val;
	int *curr_val;

	if (!*stack_a)
		return (-1);
	a = *stack_a;
	prev_val = a->content;
	a = a->next;
	while (a)
	{
		curr_val = a->content;
		if (*prev_val >= *curr_val)
		{
			if (*prev_val == *curr_val)
				return (-1);
			return (0);
		}
		a = a->next;
		prev_val = curr_val;
	}
	return (1);
}
