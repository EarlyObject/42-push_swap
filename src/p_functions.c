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
	pa(t_list **recipient, t_list **donor)
{
	put_to_other_stack(donor, recipient);
	ft_putendl_fd("pa", 1);
}

void
	pb(t_list **donor, t_list **recipient)
{
	put_to_other_stack(donor, recipient);
	ft_putendl_fd("pb", 1);
}
