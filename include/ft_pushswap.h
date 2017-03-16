/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 15:01:55 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/11 15:01:57 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# include "libft.h"
# include <limits.h>

typedef struct		s_data
{
	t_list			*stack_a;
	t_list			*stack_b;
	int				*min_list;
	int				min;
	int				max;
	int				mid;
	int				min_i;
	int				max_i;
	int				top_a;
	int				bottom_a;
	int				size_a;
	int				r_cost;
	int				rr_cost;
	int				min_b;
	int				max_b;

}					t_data;

void ft_swap(t_list **stack);
t_list  *ft_pop(t_list **stack);
void ft_pop_push(t_list **pop, t_list **push);
void ft_rotate(t_list **stack);
void ft_rev_rotate(t_list **stack);
void ft_listaddback(t_list **stack, t_list *elem);
int ft_is_sorted(t_list **stack_a);
int ft_is_rev_sorted(t_list **stack_a);
int	ft_lstcount(t_list *list);
void print_list(t_list **list);
void print_lists(t_list **stack_a, t_list **stack_b);

#endif
