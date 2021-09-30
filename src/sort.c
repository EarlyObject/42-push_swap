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

double
	average(t_list **lst)
{
	double	average;
	int		sum;
	t_list	*temp;

	sum = 0;
	temp = *lst;
	while (temp)
	{
		sum += cont_of(temp);
		temp = temp->next;
	}
	average = sum / ft_lstsize(*lst);
	return (average);
}

void
	sort_four(t_list **lst)
{
	t_list	*stack_b;
	double	avrg;

	stack_b = (t_list *)malloc(sizeof(t_list));
	stack_b->next = NULL;
	stack_b->content = NULL;
	avrg = average(lst);
	while (!is_ordered(*lst))
	{
		if (cont_of(*lst) > avrg)
			ra(lst);
		if (is_ordered(*lst))
			return ;
		pb(lst, &stack_b);
		sort_three(lst);
		pa(lst, &stack_b);
		if (!is_ordered(*lst))
			sa(&*lst);
	}
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
}
