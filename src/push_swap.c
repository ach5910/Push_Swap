/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahunt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:23:43 by ahunt             #+#    #+#             */
/*   Updated: 2017/02/21 19:23:54 by ahunt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pushswap.h"
t_list	*sort_list(t_list* lst)
{
	int		swap;
	t_list	*tmp;
	int	*data_tmp;

	swap = 1;
	if (lst == 0)
		return (lst);
	while (swap)
	{
		swap = 0;
		tmp = lst;
		while (tmp->next)
		{
			if (*(int*)tmp->content > *(int*)tmp->next->content)
			{
				data_tmp = tmp->content;
				tmp->content = tmp->next->content;
				tmp->next->content = data_tmp;
				swap = 1;
			}
			tmp = tmp->next;
		}
	}
	return (tmp);
}

void ft_get_mid(t_data *list_data)
{
	t_list *stack;
	int *midrange;
	int size;
	int temp;
	int i = 0;

	stack = list_data->stack_a;
	size = ft_lstcount(stack);
	midrange = (int*)ft_memalloc(size * sizeof(int));
	while (stack)
	{
		midrange[i++] = *(int*)stack->content;
		stack = stack->next;
	}
	i = 0;
	while (i < size - 1)
	{
		if (midrange[i] > midrange[i + 1])
		{
			temp = midrange[i];
			midrange[i] = midrange[i + 1];
			midrange[i + 1] = temp;
			i = 0;
		}
		else
			i++;
	}
	list_data->mid = midrange[size / 2];
	// ft_printf("size midrange[size / 2] = %d\n",midrange[size / 2] );
}
void ft_get_limits(t_data *list_data)
{
	int	*curr;
	t_list *stack;
	
	stack = list_data->stack_a;
	curr = stack->content;
	list_data->min = *curr;
	list_data->max = *curr;
	stack = stack->next;
	while (stack)
	{
		curr = stack->content;
		if (list_data->min > *curr)
			list_data->min = *curr;
		if (list_data->max < *curr)
			list_data->max = *curr;
		stack = stack->next;
	}
}

void ft_get_endpoints(t_data *list_data)
{
	int *curr;
	t_list *stack;

	stack = list_data->stack_a;
	list_data->top_a = *(int*)stack->content;
	while (stack->next)
		stack = stack->next;
	list_data->bottom_a = *(int*)stack->content;
}
void ft_set_min_list(t_data **list_data)
{
	int size;

	size = ft_lstcount((*list_data)->stack_a) / 2;
	(*list_data)->min_list = (int*)ft_memalloc(sizeof(int) * size);
	t_list *stack;
	int *curr;
	int i = 0;
	int j;
	int temp;

	stack = (*list_data)->stack_a;
	while (i < size)
	{
		curr = stack->content;
		(*list_data)->min_list[i] = *curr;
		stack = stack->next;
	}
	i = 0;
	j = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if ((*list_data)->min_list[i] > (*list_data)->min_list[j])
			{
				temp = (*list_data)->min_list[i];
				(*list_data)->min_list[i] = (*list_data)->min_list[j];
				(*list_data)->min_list[j] = temp;
				i = -1;
				break;
			}
			j++;
		}
		i++;
	}
	while (stack)
	{
		curr = stack->content;
		i = size;
		while (--i)
		{
			if ((*list_data)->min_list[i] > *curr)
				(*list_data)->min_list[i] = *curr;
		}
	}
}
void ft_get_rotation_costs_for_unsorted(t_data *list_data)
{
	int size;
	int index;
	t_list *stack;
	int *curr;
	int *prev;

	ft_get_limits(list_data);
	stack = list_data->stack_a;
	prev = stack->content;
	list_data->r_cost = 0;
	list_data->rr_cost = 0;
	index = 0;
	size = ft_lstcount(stack);
	while(stack->next)
	{
		stack = stack->next;
		curr = stack->content;
		if (*prev > *curr && *prev != list_data->max && *curr != list_data->min)
			break;
		prev = curr;
		index++;
	}
	list_data->min_i = index;
	list_data->r_cost = index;
	list_data->rr_cost = size - index;	
}
void ft_get_rotation_costs(t_data *list_data)
{
	int size;
	int index;
	t_list *stack;
	int *curr;

	ft_get_limits(list_data);
	stack = list_data->stack_a;
	curr = stack->content;
	list_data->r_cost = 0;
	list_data->rr_cost = 0;
	index = 0;
	size = ft_lstcount(stack);
	while(*(int*)stack->content != list_data->min)
	{
		// ft_printf("index%d", index);
		index++;
		stack = stack->next;
	}
	list_data->min_i = index;
	list_data->r_cost = index;
	list_data->rr_cost = size - index;


}
void ft_get_b_limits(t_data *list_data)
{
	int	*curr;
	t_list *stack;


	stack = list_data->stack_b;
	curr = stack->content;
	list_data->min_b = *curr;
	list_data->max_b = *curr;
	stack = stack->next;
	while (stack)
	{
		curr = stack->content;
		if (list_data->min_b > *curr)
			list_data->min_b = *curr;
		if (list_data->max_b < *curr)
			list_data->max_b = *curr;
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_data *list_data;
	// t_list *stack_a;
	// t_list *stack_b;
	int temp;
	int flag = 1;
	char *str;
	char *tmp;
	int ret;
	t_list *top_node;
	t_list *next_node;
	int *top;
	int *next;
	t_list *top_node_b;
	t_list *next_node_b;
	int *top_b;
	int *next_b;
	int *holder;
	int merge = 4;
	int debug = 0;
	char *instr[11] = {"rrb","rb", "sb", "pa", "sa", "ra", "rra", "ss", "rr", "rrr", "pb"};



	if (argc > 1)
	{
		int i = 1;
		list_data = ft_memalloc(sizeof(t_data));
		if (ft_str_index(argv[i], ' ') > 0)
		{
			tmp = argv[i];
			while (*tmp)
			{
				temp = ft_atoi(tmp);
				ft_lstadd(&(list_data->stack_a), ft_lstnew(&temp, sizeof(int*)));
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
				ft_lstadd(&(list_data->stack_a), ft_lstnew(&temp, sizeof(int)));
				i++;
			}
		}
		str = NULL;
		ft_get_limits(list_data);
		if (merge == 4)
		{
			list_data->size_a = ft_lstcount(list_data->stack_a);
			int size = list_data->size_a;
			t_list *functs;
			size /= 2;
			ft_get_mid(list_data);
			while (size)
			{
				while (*(int*)list_data->stack_a->content >= list_data->mid)
				{
					temp = 2;
					ft_rotate(&(list_data->stack_a));
					ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));

				}
				temp = 7;
				ft_pop_push(&(list_data->stack_a), &(list_data->stack_b));
				ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
				ft_get_limits(list_data);
				if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
				size--;
			}
			ft_get_b_limits(list_data);
			int a ;
			int b;
			int i = 0;
			a = 0;
			b = 0;
			size = ft_lstcount(list_data->stack_b);
			while (!(list_data->stack_b->next == NULL))
			{
				if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
				a = 0;
				top_node = list_data->stack_a;
				next_node = top_node->next;
				top = top_node->content;
				next = next_node->content;
				ft_get_limits(list_data);
				if (*top > *next && !(*next == list_data->min && *top == list_data->max))
				{
					ft_swap(&(list_data->stack_a));
					a = 1;
				}
				else if (!ft_is_sorted(&(list_data->stack_a)))
				{
					a = 2;
					ft_rotate(&(list_data->stack_a));
				}
				if (a != 0)
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				b = 0;
				top_node_b = list_data->stack_b;
				next_node_b = top_node_b->next;
				top_b = top_node_b->content;
				next_b = next_node_b->content;
				if (*top_b < *next_b && !(*next_b == list_data->max_b && *top_b == list_data->min_b))
				{
					ft_swap(&(list_data->stack_b));
					b = -1;
				}
				else if (!(ft_is_rev_sorted(&(list_data->stack_b))))
				{
					ft_rotate(&(list_data->stack_b));
					b = -2;
				}
				if (b != 0)
					ft_listaddback(&functs, ft_lstnew(&b, sizeof(int)));
				else if (a == 0 && b == 0)
				{
					size--;
					ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				}
			}
			if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
			ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
			ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
			if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
			b = 10;
			a = *((int*)functs->content);
			functs = functs->next;
			while (functs)
			{
				// a = *((int*)functs->content);
				b = *((int*)functs->content);
				if (a + b == 0 && a != 0)
				{
					if (a * a == 1)
						ft_putendl(instr[7]);
					else if (a * a == 4)
						ft_putendl(instr[8]);
					else
						ft_putendl(instr[9]);
					functs = functs->next;
					b = *((int*)functs->content);
				}
				else
					ft_putendl(instr[a + 3]);
				a = b;
				functs = functs->next;
			}
			ft_putendl(instr[a + 3]);
		}
		else if (merge == 3)//pop first half to second stack then sort both stacks, when b is sorted its inserted properly back in a
		{
			list_data->size_a = ft_lstcount(list_data->stack_a);
			int size = list_data->size_a;
			t_list *functs;
			size /= 2;
			while (size)
			{
				temp = 7;
				// ft_putendl("before pop push onto b\n");
				ft_pop_push(&(list_data->stack_a), &(list_data->stack_b));
				ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
				ft_get_limits(list_data);
				if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
				size--;
			}
			ft_get_b_limits(list_data);
			int a ;
			int b;
			int i = 0;
			a = 0;
			b = 0;
			size = ft_lstcount(list_data->stack_b);
			while (!ft_is_rev_sorted(&(list_data->stack_b->next)))
			{
				if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
				a = 0;
				top_node = list_data->stack_a;
				next_node = top_node->next;
				top = top_node->content;
				next = next_node->content;
				ft_get_limits(list_data);
				if (*top > *next && !(*next == list_data->min && *top == list_data->max))
				{
					ft_swap(&(list_data->stack_a));
					a = 1;
				}
				else if (!ft_is_sorted(&(list_data->stack_a)))
				{
					a = 2;
					ft_rotate(&(list_data->stack_a));
				}
				if (a != 0)
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				b = 0;
				ft_get_endpoints(list_data);
				top_node_b = list_data->stack_b;
				next_node_b = top_node_b->next;
				top_b = top_node_b->content;
				next_b = next_node_b->content;
				if (*top_b > list_data->top_a && *top_b < list_data->bottom_a)
				{
					temp = 0;
					ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
					ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
					top_b = next_b;
					next_node_b = next_node_b->next;
					next_b = next_node_b->content;
				}
				if (*top_b < *next_b && !(*next_b == list_data->max_b && *top_b == list_data->min_b))
				{
					ft_swap(&(list_data->stack_b));
					b = -1;
				}
				else if (!(ft_is_rev_sorted(&(list_data->stack_b))))
				{
					ft_rotate(&(list_data->stack_b));
					b = -2;
				}
				ft_get_endpoints(list_data);
				top_node_b = list_data->stack_b;
				next_node_b = top_node_b->next;
				top_b = top_node_b->content;
				next_b = next_node_b->content;
				if (*top_b > list_data->top_a && *top_b < list_data->bottom_a)
				{
					temp = 0;
					ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
					ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
				}
				if (b != 0)
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				else if (a == 0 && b == 0)
				{
					size--;
					ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				}
			}
			if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
			ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
			ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
			if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));

			// If stack B is empty swap and rev a until sorted
			while (!ft_is_sorted(&(list_data->stack_a)))
			{
				// if (debug) ft_putendl("Here");
				a = 0;
				top_node = list_data->stack_a;
				next_node = top_node->next;
				top = top_node->content;
				next = next_node->content;
				ft_get_limits(list_data);
				if (*top > *next && !(*next == list_data->min && *top == list_data->max))
				{
					ft_swap(&(list_data->stack_a));
					a = 1;
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				}
				else if (!ft_is_sorted(&(list_data->stack_a)))
				{
					// if (debug) {ft_putendl("Inside Not Sorted");}
					ft_get_rotation_costs(list_data);
					if (list_data->min_i == 0)
						ft_get_rotation_costs_for_unsorted(list_data);
					// ft_printf("min = %d\n", list_data->min);
					if(list_data->r_cost <= list_data->rr_cost)
					{
						size = list_data->r_cost;
						while (size--)
						{
							// ft_printf("r_cost less=\n" ,list_data->r_cost);
							temp = 2;
							ft_rotate(&(list_data->stack_a));
							ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
							// if (debug) {ft_putendl("rot");}
							if (debug) {print_lists(&(list_data->stack_a), &(list_data->stack_b));}
						}
					}
					else
					{
						size = list_data->rr_cost;
						while (size--)
						{
							// ft_printf("rr_cost less =\n",list_data->rr_cost );
							ft_rev_rotate(&(list_data->stack_a));
							temp = 3;
							ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
							// if (debug) {ft_putendl("revrot");}
							if (debug) {print_lists(&(list_data->stack_a), &(list_data->stack_b));}
						}
					}
				}
				
				if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
			}
			b = 10;
			a = *((int*)functs->content);
			functs = functs->next;
			while (functs)
			{
				// a = *((int*)functs->content);
				b = *((int*)functs->content);
				if (a + b == 0 && a != 0)
				{
					if (a * a == 1)
						ft_putendl(instr[7]);
					else if (a * a == 4)
						ft_putendl(instr[8]);
					else
						ft_putendl(instr[9]);
					functs = functs->next;
					b = *((int*)functs->content);
				}
				else
					ft_putendl(instr[a + 3]);
				a = b;
				functs = functs->next;
			}
			ft_putendl(instr[a + 3]);
		}
		else if (merge == 2)//pop first half to second stack then sort both stacks
		{
			list_data->size_a = ft_lstcount(list_data->stack_a);
			int size = list_data->size_a;
			t_list *functs;
			size /= 2;
			while (size)
			{
				temp = 7;
				// ft_putendl("before pop push onto b\n");
				ft_pop_push(&(list_data->stack_a), &(list_data->stack_b));
				ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
				ft_get_limits(list_data);
				if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
				size--;
			}
			ft_get_b_limits(list_data);
			int a ;
			int b;
			int i = 0;
			a = 0;
			b = 0;
			size = ft_lstcount(list_data->stack_b);
			while (!(list_data->stack_b->next == NULL))
			{
				if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
				a = 0;
				top_node = list_data->stack_a;
				next_node = top_node->next;
				top = top_node->content;
				next = next_node->content;
				ft_get_limits(list_data);
				if (*top > *next && !(*next == list_data->min && *top == list_data->max))
				{
					ft_swap(&(list_data->stack_a));
					a = 1;
				}
				else if (!ft_is_sorted(&(list_data->stack_a)))
				{
					a = 2;
					ft_rotate(&(list_data->stack_a));
				}
				if (a != 0)
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				b = 0;
				top_node_b = list_data->stack_b;
				next_node_b = top_node_b->next;
				top_b = top_node_b->content;
				next_b = next_node_b->content;
				if (*top_b < *next_b && !(*next_b == list_data->max_b && *top_b == list_data->min_b))
				{
					ft_swap(&(list_data->stack_b));
					b = -1;
				}
				else if (!(ft_is_rev_sorted(&(list_data->stack_b))))
				{
					ft_rotate(&(list_data->stack_b));
					b = -2;
				}
				if (b != 0)
					ft_listaddback(&functs, ft_lstnew(&b, sizeof(int)));
				else if (a == 0 && b == 0)
				{
					size--;
					ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				}
			}
			if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
			ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
			ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
			if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));

			// If stack B is empty swap and rev a until sorted
			while (!ft_is_sorted(&(list_data->stack_a)))
			{
				// if (debug) ft_putendl("Here");
				a = 0;
				top_node = list_data->stack_a;
				next_node = top_node->next;
				top = top_node->content;
				next = next_node->content;
				ft_get_limits(list_data);
				if (*top > *next && !(*next == list_data->min && *top == list_data->max))
				{
					ft_swap(&(list_data->stack_a));
					a = 1;
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				}
				else if (!ft_is_sorted(&(list_data->stack_a)))
				{
					// if (debug) {ft_putendl("Inside Not Sorted");}
					ft_get_rotation_costs(list_data);
					if (list_data->min_i == 0)
						ft_get_rotation_costs_for_unsorted(list_data);
					// ft_printf("min = %d\n", list_data->min);
					if(list_data->r_cost <= list_data->rr_cost)
					{
						size = list_data->r_cost;
						while (size--)
						{
							// ft_printf("r_cost less=\n" ,list_data->r_cost);
							temp = 2;
							ft_rotate(&(list_data->stack_a));
							ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
							// if (debug) {ft_putendl("rot");}
							if (debug) {print_lists(&(list_data->stack_a), &(list_data->stack_b));}
						}
					}
					else
					{
						size = list_data->rr_cost;
						while (size--)
						{
							// ft_printf("rr_cost less =\n",list_data->rr_cost );
							ft_rev_rotate(&(list_data->stack_a));
							temp = 3;
							ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
							// if (debug) {ft_putendl("revrot");}
							if (debug) {print_lists(&(list_data->stack_a), &(list_data->stack_b));}
						}
					}
				}
				
				if (debug) print_lists(&(list_data->stack_a), &(list_data->stack_b));
			}
			b = 10;
			a = *((int*)functs->content);
			functs = functs->next;
			while (functs)
			{
				// a = *((int*)functs->content);
				b = *((int*)functs->content);
				if (a + b == 0 && a != 0)
				{
					if (a * a == 1)
						ft_putendl(instr[7]);
					else if (a * a == 4)
						ft_putendl(instr[8]);
					else
						ft_putendl(instr[9]);
					functs = functs->next;
					b = *((int*)functs->content);
				}
				else
					ft_putendl(instr[a + 3]);
				a = b;
				functs = functs->next;
			}
			ft_putendl(instr[a + 3]);
		}
		else if (merge == 1)//rot thru first stack and pop first half to second stack in order
		{
			list_data->size_a = ft_lstcount(list_data->stack_a);
			int size = list_data->size_a;
			t_list *functs;
			size /= 2;
			while (size)
			{
				// ft_printf("size %d\n", size );
				ft_get_rotation_costs(list_data);
				// print_list(&(list_data->stack_a));
				while (list_data->min != *(int*)(list_data->stack_a->content))
				{
					// ft_printf("min = %d\n", list_data->min);
					if(list_data->r_cost <= list_data->rr_cost)
					{
						// ft_printf("r_cost less=\n" ,list_data->r_cost);
						temp = 2;
						ft_rotate(&(list_data->stack_a));
					}
					else
					{
						// ft_printf("rr_cost less =\n",list_data->rr_cost );
						ft_rev_rotate(&(list_data->stack_a));
						temp = 3;
					}
					ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));

				}
					// print_lists(&(list_data->stack_a), &(list_data->stack_b));
				// ft_printf("size2%d\n", size);
				temp = 7;
				// ft_putendl("before pop push onto b\n");
				ft_pop_push(&(list_data->stack_a), &(list_data->stack_b));
				ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
				ft_get_limits(list_data);
				size--;
			}
			if (ft_is_sorted(&(list_data->stack_a)))
			{
				while (list_data->stack_b->next != NULL)
				{
					temp = 0;
					ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
					ft_listaddback(&functs, ft_lstnew(&temp, sizeof(int)));
				}
			}
			ft_get_b_limits(list_data);
			int a ;
			int b;
			int i = 0;
			a = 0;
			b = 10;
			size = ft_lstcount(list_data->stack_b);
			while (list_data->stack_b->next != NULL)
			{
				// print_lists(&(list_data->stack_a), &(list_data->stack_b));
				a = 0;
				top_node = list_data->stack_a;
				next_node = top_node->next;
				top = top_node->content;
				next = next_node->content;
				ft_get_limits(list_data);
				if (*top > *next && !(*next == list_data->min && *top == list_data->max))
				{
					ft_swap(&(list_data->stack_a));
					a = 1;
				}
				else if (!ft_is_sorted(&(list_data->stack_a)))
				{
					a = 2;
					ft_rotate(&(list_data->stack_a));
				}
				if (a != 0)
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				b = 0;
				top_node_b = list_data->stack_b;
				next_node_b = top_node_b->next;
				top_b = top_node_b->content;
				next_b = next_node_b->content;
				if (*top_b < *next_b && !(*next_b == list_data->max_b && *top_b == list_data->min_b))
				{
					ft_swap(&(list_data->stack_b));
					b = -1;
				}
				else if (!(ft_is_rev_sorted(&(list_data->stack_b))))
				{
					ft_rotate(&(list_data->stack_b));
					b = -2;
				}
				if (b != 0)
					ft_listaddback(&functs, ft_lstnew(&b, sizeof(int)));
				else if (a == 0)
				{
					size--;
					ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
					ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
				}
			}
			// print_lists(&(list_data->stack_a), &(list_data->stack_b));
			ft_pop_push(&(list_data->stack_b), &(list_data->stack_a));
			ft_listaddback(&functs, ft_lstnew(&a, sizeof(int)));
			// print_lists(&(list_data->stack_a), &(list_data->stack_b));
			b = 10;
			a = *((int*)functs->content);
			functs = functs->next;
			while (functs)
			{
				b = *((int*)functs->content);
				if (a + b == 0 && a != 0)
				{
					if (a == 1)
						ft_putendl(instr[7]);
					else if (a == 2)
						ft_putendl(instr[8]);
					else
						ft_putendl(instr[9]);
					functs = functs->next;
					b = *((int*)functs->content);
				}
				else
					ft_putendl(instr[a + 3]);
				a = b;
				functs = functs->next;
			}
			ft_putendl(instr[a + 3]);
		}
		else
		{
			while (!ft_is_sorted(&(list_data->stack_a)))
			{
				top_node = list_data->stack_a;
				next_node = top_node->next;
				top = top_node->content;
				next = next_node->content;
				if (*top > *next && *next != list_data->max && *top != list_data->max)
				{
					ft_swap(&(list_data->stack_a));
					ft_putendl("sa");
				}
				else
				{
					ft_rotate(&(list_data->stack_a));
					ft_putendl("ra");
				}
				// ft_putchar('\n');
				// print_list(&(list_data->stack_a));
				// ft_putchar('\n');
			}
		}
		// ft_printf("Max %d\nMin %d\n", list_data->max, list_data->min);
		if (debug)
		{
			if ((temp = ft_is_sorted(&(list_data->stack_a))) == 1)
				ft_putstr(BD_GREEN"OK\n"RESET);
			else if (temp == 0)
				ft_putstr(BD_RED"KO\n"RESET);
			else
				ft_putstr(BD_RED"Error\n"RESET);
			print_list(&(list_data->stack_a));
		}
		
	}



	return (0);
}
