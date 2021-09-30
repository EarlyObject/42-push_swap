/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:23:28 by asydykna          #+#    #+#             */
/*   Updated: 2021/02/07 17:18:06 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*t_list
	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}*/

t_list
	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	/*if (!lst)
		return (lst);*/
	temp = lst;
	while (temp && temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}
