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
	printf("sa\n");
}

void
	sb(t_list **lst)
{
	swap_two(lst);
	printf("sb\n");
}

void
	ss(t_list **a, t_list **b)
{
	swap_two(a);
	swap_two(b);
	printf("ss\n");
}
