/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_place.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:04:10 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/08 12:04:23 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

char
	get_recipient_name(char donor_name)
{
	char	recipient_name;

	if (donor_name == 'a')
		recipient_name = 'b';
	else
		recipient_name = 'a';
	return (recipient_name);
}

void
	rotate_stack(t_list **recipient, char donor_name, int steps,
			 bool rotate_down)
{
	while (steps)
	{
		if (donor_name == 'b')
		{
			if (rotate_down)
				ra(recipient);
			else
				rra(recipient);
		}
		else
		{
			if (rotate_down)
				rb(recipient);
			else
				rrb(recipient);
		}
		steps--;
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
	calc_steps_and_rotate(int donor_val, t_list **recipient, char donor_name)
{
	int		steps;
	bool	rotate_down;

	steps = -1;
	rotate_down = true;
	steps = calc_steps(steps, *recipient, donor_val);
	if (ft_lstsize(*recipient) - steps < steps)
	{
		rotate_down = false;
		steps = ft_lstsize(*recipient) - steps;
	}
	rotate_stack(recipient, donor_name, steps, rotate_down);
}

void
	prepare_place(int donor_val, t_list **recipient, char donor_name,
			  bool sort_rcpt_ascending)
{
	char	recipient_name;

	if (!*recipient)
		return ;
	recipient_name = get_recipient_name(donor_name);
	if (donor_val > get_max(recipient))
	{
		if (sort_rcpt_ascending == true)
		{
			if (is_sorted(*recipient))
				return ;
		}
		else
		{
			if (is_sorted(*recipient) || is_reverse_sorted(*recipient))
				return ;
		}
		while (!is_sorted(*recipient))
			iterate_lst(recipient, recipient_name);
		return ;
	}
	calc_steps_and_rotate(donor_val, recipient, donor_name);
}
