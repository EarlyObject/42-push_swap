/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:31:48 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 11:32:04 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	sa(t_list **lst)
{
	swap_two(lst);
	ft_putendl_fd("sa", 1);
}

void
	sb(t_list **lst)
{
	swap_two(lst);
	ft_putendl_fd("sb", 1);
}

void
	ss(t_list **a, t_list **b)
{
	swap_two(a);
	swap_two(b);
	ft_putendl_fd("ss", 1);
}
