/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:39:03 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/29 12:39:12 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int
	cont_of(t_list *lst)
{
	return (*(int *)lst->content);
}

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
	if (is_ordered(*lst))
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

int
	is_sorted_and_top_bgst(t_list **lst)
{
	if (is_ordered((*lst)->next) && cont_of(*lst) > cont_of(ft_lstlast(*lst)))
	{
		ra(lst);
		return (1);
	}
	return (0);
}

void
	iterate_lst(t_list **lst)
{
	if (cont_of(ft_lstlast(*lst)) < cont_of(*lst)
		&& cont_of(ft_lstlast(*lst)) < cont_of((*lst)->next->next))
		rra(lst);
	else
	{
		ra(lst);
		ra(lst);
	}
}

void
	insert_mid_num(t_list **lst, t_list *stack_b)
{
	if (cont_of(stack_b) < cont_of((*lst)->next))
		ra(lst);
	else
		rra(lst);
}

void
	sort_four(t_list **lst)
{
	t_list	*stack_b;

	stack_b = (t_list *)malloc(sizeof(t_list));
	stack_b->next = NULL;
	stack_b->content = NULL;
	if (is_sorted_and_top_bgst(lst))
	{
		free_list(stack_b);
		return ;
	}
	pb(lst, &stack_b);
	sort_three(lst);
	if (cont_of(stack_b) < cont_of(*lst) || cont_of(stack_b) > cont_of(ft_lstlast(*lst)))
		pa(lst, &stack_b);
	else
	{
		insert_mid_num(lst, stack_b);
		pa(lst, &stack_b);
	}
	if (!is_sorted_and_top_bgst(lst))
		while (!is_ordered(*lst))
			iterate_lst(lst);
	free_list(stack_b);
}

void
	sort_five(t_list **lst)
{
	t_list	*stack_b;
	//double	avrg;

	stack_b = (t_list *)malloc(sizeof(t_list));
	stack_b->next = NULL;
	stack_b->content = NULL;
//	avrg = average(lst);
	while (!is_ordered(*lst))
	{
		/*if (cont_of(*lst) > avrg)
			ra(lst);
		if (cont_of(*lst) > avrg)
			ra(lst);*/
		if (cont_of(*lst) > cont_of((*lst)->next))
			sa(lst);
		if (is_ordered(*lst))
			return ;
		pb(lst, &stack_b);
		sort_four(lst);
		pa(lst, &stack_b);
		if (!is_ordered(*lst))
			sa(&*lst);
	}
	free_list(stack_b);
	print_lst(*lst);
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
	else if (size == 4)
		sort_four(lst);
	else if (size == 5)
		sort_five(lst);
}
