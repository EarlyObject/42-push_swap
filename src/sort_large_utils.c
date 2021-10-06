/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 15:46:40 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/07 21:45:02 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int
	get_chunks(int size)
{
	int	chunks;
	int	optimum;

	optimum = get_optimum(size);
	chunks = size / optimum;
	if (chunks < 1)
		chunks = 1;
	else if (size % optimum != 0)
		chunks += 1;
	return (chunks);
}

int
	get_optimum(int size)
{
	int	optimum;

	if (size < 20)
		optimum = 10;
	else if (size >= 20 && size <= 100)
		optimum = 20;
	else
		optimum = 40;
	return (optimum);
}

int *
	cp_lst_to_arr(t_list *const *lst, int size)
{
	int		*arr;
	t_list	*temp;
	int		i;

	arr = (int *) malloc(size * sizeof(int));
	temp = *lst;
	i = 0;
	while (temp)
	{
		arr[i] = cont_of(temp);
		i++;
		temp = temp->next;
	}
	return (arr);
}
