/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:33:51 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/06 12:36:23 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	ft_error_exit(char *err_message, int num, int exit_code)
{
	ft_putendl_fd("Error", 2);
	ft_putstr_fd(err_message, 2);
	if (num)
		ft_putnbr_fd(num, 2);
	ft_putendl_fd("", 2);
	exit(exit_code);
}

t_list *
	make_lst(void )
{
	t_list	*lst;

	lst = (t_list *)malloc(sizeof(t_list));
	lst->content = NULL;
	lst->next = NULL;
	return (lst);
}

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
