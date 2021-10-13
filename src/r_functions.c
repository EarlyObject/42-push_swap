/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:52:27 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 11:52:32 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	ra(t_list **lst)
{
	top_to_bottom(lst);
	ft_putendl_fd("ra", 1);
}

void
	rb(t_list **lst)
{
	top_to_bottom(lst);
	ft_putendl_fd("rb", 1);
}

void
	rr(t_list **a, t_list **b)
{
	top_to_bottom(a);
	top_to_bottom(b);
	ft_putendl_fd("rr", 1);
}
