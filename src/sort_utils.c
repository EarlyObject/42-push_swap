/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 12:58:46 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/01 12:58:59 by asydykna         ###   ########.fr       */
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

int
	get_next_big_pos(int position, int position_max, t_list *temp,
					 t_list *stack_b)
{
	int	target;
	int	max;
	int	next_biggest;
	int	i;

	target = cont_of(stack_b);
	max = (int)get_max(&temp);
	next_biggest = max;
	i = -1;
	while (temp)
	{
		i++;
		if (cont_of(temp) == max)
			position_max = i;
		if (cont_of(temp) > target && cont_of(temp) < next_biggest)
		{
			next_biggest = cont_of(temp);
			position = i;
		}
		temp = temp->next;
	}
	if (target == max || position < 0)
		position = position_max;
	return (position);
}

void
	find_place_for_b(t_list **lst, t_list *stack_b)
{
	int		position;
	int		position_max;
	t_list	*temp;
	bool	move_down;

	if (cont_of(stack_b) > get_max(lst))
		return ;
	position = -1;
	position_max = -1;
	temp = *lst;
	move_down = true;
	position = get_next_big_pos(position, position_max, temp, stack_b);
	if (ft_lstsize(*lst) - position < position)
	{
		move_down = false;
		position = ft_lstsize(*lst) - position;
	}
	while (position)
	{
		if (move_down)
			ra(lst);
		else
			rra(lst);
		position--;
	}
}

t_list
	*find_place_insert(t_list **lst, t_list **stack_b)
{
	find_place_for_b(lst, (*stack_b));
	pa(lst, stack_b);
	return (*stack_b);
}
