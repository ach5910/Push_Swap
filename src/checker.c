/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 22:29:54 by ahunt             #+#    #+#             */
/*   Updated: 2017/01/10 22:29:57 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"

// void ft_sa(t_data **list_data)
// {
// 	ft_swap(&((*list_data)->stack_a));
// }
//
// void ft_sb(t_data **list_data)
// {
// 	ft_swap(&((*list_data)->stack_b));
// }

void ft_ss(t_list **a, t_list **b)
{
	ft_swap(a);
	ft_swap(b);
}

// void ft_pa(t_data **list_data)
// {
// 	ft_printf("\nin pop a\n");
// 	ft_pop_push(&((*list_data)->stack_b), &((*list_data)->stack_b));
// 	ft_printf("\nleaving pop a\n");
// }
//
// void ft_pb(t_data **list_data)
// {
// 	ft_printf("\nin pop b\n");
// 	ft_pop_push(&((*list_data)->stack_b), &((*list_data)->stack_a));
// 	ft_printf("\nleaving pop b\n");
// }

// void ft_ra(t_data **list_data)
// {
// 	ft_rotate(&((*list_data)->stack_a));
// }
//
// void ft_rb(t_data **list_data)
// {
// 	ft_rotate(&((*list_data)->stack_b));
// }

void ft_rr(t_list **a, t_list **b)
{
	ft_rotate(a);
	ft_rotate(b);
}

// void ft_rra(t_data **list_data)
// {
// 	ft_rev_rotate(&((*list_data)->stack_a));
// }
//
// void ft_rrb(t_data **list_data)
// {
// 	ft_rev_rotate(&((*list_data)->stack_b));
// }

void ft_rrr(t_list **a, t_list **b)
{
	ft_rev_rotate(a);
	ft_rev_rotate(b);
}

int	main(int argc, char **argv)
{
	t_data *list_data;
	// t_list *stack_a;
	// t_list *stack_b;
	int temp;
	int flag = 0;
	char *str;
	int ret;
	char *tmp;

	if (argc > 1)
	{
		list_data = ft_memalloc(sizeof(t_data));
		// s,tack_b = ft_memalloc(sizeof(t_list));
		int i = 1;
		if (ft_str_index(argv[i], ' ') > 0)
		{
			tmp = argv[i];
			while (*tmp)
			{
				temp = ft_atoi(tmp);
				ft_listaddback(&(list_data->stack_a), ft_lstnew(&temp, sizeof(int*)));
				while (*tmp == ' ')
					tmp++;
				if ((ret = ft_str_index(tmp, ' ') != -1))
					tmp = tmp + ++ret;
				else
					*tmp = '\0';
			}
			i++;
		}
		else
		{
			while (i < argc && ft_isdigit(argv[i][0]))
			{
				temp = ft_atoi(argv[i]);
				ft_listaddback(&(list_data->stack_a), ft_lstnew(&temp, sizeof(int*)));
				i++;
			}
		}
		str = NULL;
		while(get_next_line(0, &str))
		{
			flag++;
			if (ft_strequ("sa", str))
				ft_swap(&(list_data->stack_a));
			else if (ft_strequ("sb", str))
				ft_swap(&(list_data->stack_b));
			else if (ft_strequ("ss", str))
				ft_ss(&(list_data->stack_a), &(list_data->stack_b));
			else if (ft_strequ("pa", str))
				ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
			else if (ft_strequ("pb", str))
				ft_pop_push(&(list_data->stack_a), &(list_data->stack_b));
			else if (ft_strequ("ra", str))
				ft_rotate(&(list_data->stack_a));
			else if (ft_strequ("rb", str))
				ft_rotate(&(list_data->stack_b));
			else if (ft_strequ("rr", str))
				ft_rr(&(list_data->stack_a), &(list_data->stack_b));
			else if (ft_strequ("rra", str))
				ft_rev_rotate(&(list_data->stack_a));
			else if (ft_strequ("rrb", str))
				ft_rev_rotate(&(list_data->stack_b));
			else if (ft_strequ("rrr", str))
				ft_rrr(&(list_data->stack_a), &(list_data->stack_b));
			else
				ft_putstr(BD_RED"Error\n"RESET);
		}
		// while (i < argc)
		// {
		// 	if (ft_strequ("sa", argv[i]))
		// 		ft_swap(&(list_data->stack_a));
		// 	else if (ft_strequ("sb", argv[i]))
		// 		ft_swap(&(list_data->stack_b));
		// 	else if (ft_strequ("ss", argv[i]))
		// 		ft_ss(&(list_data->stack_a), &(list_data->stack_b));
		// 	else if (ft_strequ("pa", argv[i]))
		// 		ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
		// 	else if (ft_strequ("pb", argv[i]))
		// 		ft_pop_push(&(list_data->stack_a), &(list_data->stack_b));
		// 	else if (ft_strequ("ra", argv[i]))
		// 		ft_rotate(&(list_data->stack_a));
		// 	else if (ft_strequ("rb", argv[i]))
		// 		ft_rotate(&(list_data->stack_b));
		// 	else if (ft_strequ("rr", argv[i]))
		// 		ft_rr(&(list_data->stack_a), &(list_data->stack_b));
		// 	else if (ft_strequ("rra", argv[i]))
		// 		ft_rev_rotate(&(list_data->stack_a));
		// 	else if (ft_strequ("rrb", argv[i]))
		// 		ft_rev_rotate(&(list_data->stack_b));
		// 	else if (ft_strequ("rrr", argv[i]))
		// 		ft_rrr(&(list_data->stack_a), &(list_data->stack_b));
		// 	else
		// 		ft_putstr(BD_RED"Error\n"RESET);
		// 	i++;
		// }
		if ((temp = ft_is_sorted(&(list_data->stack_a))) == 1)
			ft_printf(BD_GREEN"OK\nInstruction Calls = %d\n"RESET, flag);
		else if (temp == 0)
			ft_printf(BD_RED"KO\nInstruction Calls = %d\n"RESET, flag);
		else
			ft_putstr(BD_RED"Error\n"RESET);
		print_list(&(list_data->stack_a));
	}


	// t_list *stack_b;
	//
	// stack_a = NULL;
	// stack_b = NULL;
	// int args[] = {1, 4, 56, 5, 0, 6, 34, 3, 8, 2, 12};
	// int brgs[] = {2, 7, 77, 3, 8, 33, 15, 1, 0, 4, 12};
	// int x = 0;
	// while (x < 11)
	// {
	// 	ft_listaddback(&(list_data->stack_a), ft_lstnew(&args[x], sizeof(int*)));
	// 	ft_listaddback(&(list_data->stack_b), ft_lstnew(&brgs[x], sizeof(int*)));
	// 	x++;
	// }
	// print_lists(&(list_data->stack_a), &(list_data->stack_b));
	// ft_printf(IT_CYAN"Swap First 2\n"RESET);
	// ft_swap(&(list_data->stack_a));
	// print_lists(&(list_data->stack_a), &(list_data->stack_b));
	// ft_printf(IT_CYAN"Rotate\n"RESET);
	// ft_rotate(&(list_data->stack_a));
	// print_lists(&(list_data->stack_a), &(list_data->stack_b));
	// ft_printf(IT_CYAN"Rev Rotate\n"RESET);
	// ft_rev_rotate(&(list_data->stack_a));
	// print_lists(&(list_data->stack_a), &(list_data->stack_b));
	// ft_printf(IT_CYAN"POP A - PUSH B\n"RESET);
	// ft_pop_push(&(list_data->stack_a), &(list_data->stack_b));
	// print_lists(&(list_data->stack_a), &(list_data->stack_b));
	return (0);
}
