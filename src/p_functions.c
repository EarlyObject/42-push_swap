/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:27:17 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 15:30:29 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	pa(t_list **a, t_list **b)
{
	put_to_other_stack(a, b);
	printf("pa");
}

void
	pb(t_list **a, t_list **b)
{
	put_to_other_stack(b, a);
	printf("pb");
}
