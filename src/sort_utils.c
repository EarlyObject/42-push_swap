/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:58:46 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/06 12:36:17 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int
	top_bgst_then_sorted(t_list **lst)
{
	if (is_sorted((*lst)->next) && cont_of(*lst) > cont_of(ft_lstlast(*lst)))
	{
		ra(lst);
		return (1);
	}
	return (0);
}

int
	get_idx_of(double min, t_list *lst)
{
	int	idx;

	idx = -1;
	while (lst && lst->content)
	{
		idx++;
		if (cont_of(lst) == (int)min)
			return (idx);
		lst = lst->next;
	}
	return (idx);
}

void
	iterate_lst(t_list **lst, char stack_name)
{
	double	min;
	int		size;
	int		idx_min;
	int		steps;

	min = get_min(lst);
	size = ft_lstsize(*lst);
	idx_min = get_idx_of(min, *lst);
	steps = size - idx_min;
	if (idx_min < steps)
	{
		if (stack_name == 'a')
			ra(lst);
		else
			rb(lst);
	}
	else
	{
		if (stack_name == 'a')
			rra(lst);
		else
			rrb(lst);
	}
}

bool
	is_ordered_not_sorted(t_list *lst)
{
	t_list	*start;
	t_list	*end;
	t_list	*temp_start;
	bool	sorted;
	int		min;

	min = (int)get_min(&lst);
	start = lst;
	end = ft_lstlast(lst);
	end->next = lst;
	while (true)
	{
		if (cont_of(lst->next) == min)
		{
			temp_start = lst->next;
			lst->next = NULL;
			sorted = is_sorted(temp_start);
			break ;
		}
		lst = lst->next;
	}
	ft_lstlast(temp_start)->next = temp_start;
	lst = start;
	end->next = NULL;
	return (sorted);
}
