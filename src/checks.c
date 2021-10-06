/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:12:41 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/06 12:35:31 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int
	is_sorted(t_list *lst)
{
	while (lst)
	{
		if (lst->next)
		{
			if (cont_of(lst) > cont_of(lst->next))
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

int
	is_reverse_sorted(t_list *lst)
{
	while (lst)
	{
		if (lst->next)
		{
			if (cont_of(lst) < cont_of(lst->next))
				return (0);
		}
		lst = lst->next;
	}
	return (1);
}

double
	get_max(t_list **lst)
{
	double	max;
	t_list	*temp;

	temp = *lst;
	max = INT_MIN;
	while (temp && temp->content)
	{
		if (cont_of(temp) > max)
			max = cont_of(temp);
		temp = temp->next;
	}
	return (max);
}

double
	get_min(t_list **lst)
{
	double	min;
	t_list	*temp;

	temp = *lst;
	min = INT_MAX;
	while (temp)
	{
		if (cont_of(temp) < min)
			min = cont_of(temp);
		temp = temp->next;
	}
	return (min);
}

void
	duplicate_check(int num, t_list *lst)
{
	while (lst)
	{
		if (cont_of(lst) == num)
			ft_error_exit("Duplicate number: ", num, 0);
		lst = lst->next;
	}
}
