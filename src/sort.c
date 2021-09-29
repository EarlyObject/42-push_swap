/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:39:03 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/29 12:39:12 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	sort_lst(t_list **lst)
{
	int		size;
	t_list	*one;
	t_list	*two;

	one = *lst;
	two = one->next;
	size = ft_lstsize(*lst);
	if (size == 2)
	{
		if (*(int *)one->content > *(int *)two->content)
			sa(lst);
	}
}