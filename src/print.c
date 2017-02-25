/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 18:37:41 by ahunt             #+#    #+#             */
/*   Updated: 2017/02/21 18:37:43 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

void	print_list(t_list **list)
{
	t_list	*link;
	int		*i;

	link = *list;
	while (link)
	{
		i = link->content;
		ft_printf("%d\n", *i);
		link = link->next;
	}
}

void	print_lists(t_list **stack_a, t_list **stack_b)
{
	t_list	*a;
	t_list	*b;
	int		*i;
	int		*j;

	a = *stack_a;
	b = *stack_b;
	while (a || b)
	{
		if (a)
		{
			i = a->content;
			ft_printf(BD_RED"%-3d"RESET, *i);
			a = a->next;
		}
		else
			ft_printf("%-3c", ' ');
		if (b)
		{
			j = b->content;
			ft_printf(BD_GREEN"%d"RESET, *j);
			b = b->next;
		}
		ft_printf("\n");
	}
	ft_printf("-----\n");
	ft_printf(BD_RED"%-3c"RESET, 'a');
	ft_printf(BD_GREEN"b\n\n"RESET);
}
