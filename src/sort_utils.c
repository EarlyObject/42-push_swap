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
	calc_steps(int steps, t_list *recipient, int target)
{
	int	max;
	int	idx_max;
	int	next_biggest;
	int	i;

	max = (int)get_max(&recipient);
	idx_max = -1;
	next_biggest = max;
	i = -1;
	while (recipient)
	{
		i++;
		if (cont_of(recipient) == max)
			idx_max = i;
		if (cont_of(recipient) > target && cont_of(recipient) < next_biggest)
		{
			next_biggest = cont_of(recipient);
			steps = i;
		}
		recipient = recipient->next;
	}
	if (target == max || steps < 0)
		steps = idx_max;
	return (steps);
}

void
	prepare_place(int donor_val, t_list **recipient, char donor_name)
{
	int		steps;
	bool	move_down;
	char	recipient_name;

	if (!*recipient)
		return ;
	if (donor_name == 'a')
		recipient_name = 'b';
	else
		recipient_name = 'a';
	if (donor_val > get_max(recipient))
	{
		if (is_sorted(*recipient)
			|| is_reverse_sorted(*recipient))
			return ;
		else
		{
			//print_lst(*recipient);
			while (!is_sorted(*recipient))
				iterate_lst(recipient, recipient_name); //проверить целесообразность
			return ;
		}
	}
	steps = -1;
	move_down = true;
	steps = calc_steps(steps, *recipient, donor_val);
	if (ft_lstsize(*recipient) - steps < steps)
	{
		move_down = false;
		steps = ft_lstsize(*recipient) - steps;
	}
	while (steps)
	{
		if (donor_name == 'b')
		{
			if (move_down)
				ra(recipient);
			else
				rra(recipient);
		}
		else
		{
			if (move_down)
				rb(recipient);
			else
				rrb(recipient);
		}
		steps--;
	}
}

void
	prepare_place_ascending(int donor_val, t_list **recipient, char donor_name)
{
	int		steps;
	bool	move_down;
	char	recipient_name;

	if (!*recipient)
		return ;
	if (donor_name == 'a')
		recipient_name = 'b';
	else
		recipient_name = 'a';
	if (donor_val > get_max(recipient))
	{
		if (is_sorted(*recipient))
			return ;
		else
		{
			//print_lst(*recipient);
			while (!is_sorted(*recipient))
				iterate_lst(recipient, recipient_name); //проверить целесообразность
			return ;
		}
	}
	steps = -1;
	move_down = true;
	steps = calc_steps(steps, *recipient, donor_val);
	if (ft_lstsize(*recipient) - steps < steps)
	{
		move_down = false;
		steps = ft_lstsize(*recipient) - steps;
	}
	while (steps)
	{
		if (donor_name == 'b')
		{
			if (move_down)
				ra(recipient);
			else
				rra(recipient);
		}
		else
		{
			if (move_down)
				rb(recipient);
			else
				rrb(recipient);
		}
		steps--;
	}
}

void
	find_place_insert(t_list **donor, t_list **recipient, char donor_name)
{
	prepare_place(cont_of(*donor), recipient, donor_name);
	if (donor_name == 'a')
		pa(recipient, donor);
	else
		pb(donor, recipient);
}
