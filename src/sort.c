/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:39:03 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/06 12:36:12 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	sort_two(t_list **lst)
{
	t_list	*one;
	t_list	*two;

	one = *lst;
	two = one->next;
	if (*(int *)one->content > *(int *)two->content)
		sa(lst);
}

void
	sort_three(t_list **lst)
{
	t_list	*one;
	t_list	*two;
	t_list	*three;

	one = *lst;
	two = one->next;
	three = two->next;
	if (is_sorted(*lst))
		return ;
	if (cont_of(one) > cont_of(two) && cont_of(one) < cont_of(three))
		sa(lst);
	else if (cont_of(two) < cont_of(one) && cont_of(two) > cont_of(three))
	{
		sa(lst);
		rra(lst);
	}
	else if (cont_of(three) > cont_of(two) && cont_of(three) < cont_of(one))
		ra(lst);
	else if (cont_of(three) > cont_of(one) & cont_of(three) < cont_of(two))
	{
		sa(lst);
		ra(lst);
	}
	else if (cont_of(one) > cont_of(three) && cont_of(one) < cont_of(two))
		rra(lst);
}

void
	sort_four(t_list **lst)
{
	t_list	*stack_b;

	stack_b = (t_list *)malloc(sizeof(t_list));
	stack_b->next = NULL;
	stack_b->content = NULL;
	if (top_bgst_then_sorted(lst))
	{
		free_list(stack_b);
		return ;
	}
	if (!is_ordered_not_sorted(*lst))
	{
		pb(lst, &stack_b);
		sort_three(lst);
		prepare_place(cont_of(stack_b), lst, 'b', true);
		pa(lst, &stack_b);
	}
	if (!top_bgst_then_sorted(lst))
		while (!is_sorted(*lst))
			iterate_lst(lst, 'a');
	free_list(stack_b);
}

void
	sort_five(t_list **lst)
{
	t_list	*stack_b;

	stack_b = (t_list *)malloc(sizeof(t_list));
	stack_b->next = NULL;
	stack_b->content = NULL;
	if (top_bgst_then_sorted(lst))
	{
		free_list(stack_b);
		return ;
	}
	if (!is_ordered_not_sorted(*lst))
	{
		while (ft_lstsize(*lst) > 3)
			pb(lst, &stack_b);
		sort_three(lst);
		while (stack_b && stack_b->content)
		{
			prepare_place(cont_of(stack_b), lst, 'b', 0);
			pa(lst, &stack_b);
		}
	}
	while (!is_sorted(*lst))
		iterate_lst(lst, 'a');
	free_list(stack_b);
}

void
	sort_lst(t_list **lst)
{
	int		size;

	size = ft_lstsize(*lst);
	if (size == 2)
		sort_two(lst);
	else if (size == 3)
		sort_three(lst);
	else if (size == 4 || size == 5)
		sort_five(lst);
	else
		sort_others(lst);
}
