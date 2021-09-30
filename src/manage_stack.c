/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:51:37 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/29 12:52:04 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	swap_two(t_list **lst)
{
	t_list	*first;
	t_list	*temp;

	first = *lst;
	temp = first->next;
	first->next = temp->next;
	temp->next = first;
	*lst = temp;
}

void
	top_to_bottom(t_list **lst)
{
	t_list	*first;
	t_list	*temp;

	first = *lst;
	temp = first->next;
	first->next = NULL;
	ft_lstadd_back(&temp, first);
	*lst = temp;
}

void
	bottom_to_top(t_list **lst)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	ft_lstpenultimate(*lst)->next = NULL;
	last->next = *lst;
	*lst = last;
}

void
	put_to_other_stack(t_list **a, t_list **b)
{
	t_list	*temp;

	temp = (*a)->next;
	(*a)->next = *b;
	*b = *a;
	*a = temp;
}
