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

int
	find_max_then_stop(int tmp, int start, t_list **lst)
{
	int	max;

	max = cont_of(*lst);
	*lst = (*lst)->next;
	while ((*lst))
	{
		tmp = cont_of((*lst));
		if (tmp < max || tmp > start)
		{
			return (max);
		}
		max = tmp;
		(*lst) = (*lst)->next;
	}
	return (tmp);
}

bool
	is_ordered_not_sorted(t_list *lst)
{
	int	head;
	int	tmp;

	tmp = 0;
	head = cont_of(lst);
	find_max_then_stop(tmp, INT_MAX - 1, &lst);
	find_max_then_stop(tmp, head, &lst);
	if (lst)
		return (false);
	return (true);
}
