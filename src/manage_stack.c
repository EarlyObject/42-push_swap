/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:51:37 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/06 12:36:02 by asydykna         ###   ########.fr       */
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
	t_list	*penultimate;

	last = ft_lstlast(*lst);
	penultimate = ft_lstpenultimate(*lst);
	if (penultimate)
		ft_lstpenultimate(*lst)->next = NULL;
	last->next = *lst;
	*lst = last;

	/*last = ft_lstlast(*lst);
	ft_lstpenultimate(*lst)->next = NULL;
	last->next = *lst;
	*lst = last;*/
}

void
	put_to_other_stack(t_list **donor, t_list **recipient)
{
	//t_list *pretmp;
	t_list	*tmp;

	//pretmp = *donor;
	tmp = (*donor)->next;
	if (*recipient && (*recipient)->content)
	{
		(*donor)->next = *recipient;
	}
	else
	{
		(*donor)->next = NULL;
		free(*recipient);
	}
	*recipient = *donor;
	*donor = tmp;
}


int
	cont_of(t_list *lst)
{
	if (lst && lst->content)
		return (*(int *)lst->content);
	exit (-1); //check to free memory
}
