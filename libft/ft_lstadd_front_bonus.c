/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 08:55:06 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 08:29:05 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void
	ft_lstadd_front(t_list **alst, t_list *new)
{
	if (!new)
		return ;
	if (alst)
	{
		if (*alst)
			new->next = *alst;
	}
	*alst = new;
}
