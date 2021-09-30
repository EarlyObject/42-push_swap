/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 15:12:41 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/29 15:12:57 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int
	is_ordered(t_list *lst)
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
