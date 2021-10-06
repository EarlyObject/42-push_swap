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
	perrorexit(void)
{
	ft_putendl_fd("Error", 2);
	exit (0);
}

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

void
	print_lst(t_list *lst)
{
	t_list	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp && tmp->content)
	{
		printf("%d  %d\n", i, *(int *)tmp->content);
		tmp = tmp->next;
		i++;
	}
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
