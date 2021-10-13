/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 12:17:50 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 15:27:51 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	rra(t_list **lst)
{
	bottom_to_top(lst);
	ft_putendl_fd("rra", 1);
}

void
	rrb(t_list **lst)
{
	bottom_to_top(lst);
	ft_putendl_fd("rrb", 1);
}

void
	rrr(t_list **a, t_list **b)
{
	bottom_to_top(a);
	bottom_to_top(b);
	ft_putendl_fd("rrr", 1);
}
