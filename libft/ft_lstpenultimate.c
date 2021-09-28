/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_penultimate.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 15:14:43 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 15:18:39 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** SYNOPSIS: find the one before last element of the list
**
** DESCRIPTION:
** 		Returns the last element of the list.
*/

t_list
	*ft_lstpenultimate(t_list *lst)
{
	t_list	*next;

	while (lst)
	{
		next = lst->next;
		if (next)
			if (!next->next)
				return (lst);
		lst = next;
	}
	return (NULL);
}
