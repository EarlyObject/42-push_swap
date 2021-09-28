/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:33:51 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 11:36:20 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <string.h>

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
	t_list	*first_b;
	t_list	*temp;

	temp = NULL;
	first_b = *b;
	temp = first_b->next;
	first_b->next = *a;
	*a = first_b;
	*b = temp;
}

void
	print_lst(t_list *lst)
{
	t_list	*tmp;

	printf("print_lst:\n");
	tmp = lst;
	while (tmp && tmp->content)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
}
