/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:20:49 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 10:03:39 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	my_leaks(void)
{
	system("leaks push_swap");
}

int
	build_lst(char *const *argv, t_list **list)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		ft_lstadd_front(list, ft_lstnew(argv[i]));
		(i)++;
	}
	return (i - 1);
}

void
	free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list);
		list = temp;
	}
}

int
	main(int argc, char *argv[])
{
	int		size;
	t_list	*list;
	t_list	*list2;

	if (argc < 2)
		printf("Introduce arguments");
	list = NULL;
	size = build_lst(argv, &list);
	printf("\ninitial list:\n");
	print_lst(list);
	list2 = ft_lstnew("80");
	ft_lstadd_front(&list2, ft_lstnew("90"));
	ft_lstadd_front(&list2, ft_lstnew("100"));
	printf("\ninitial list2:\n");
	print_lst(list2);
	ss(&list, &list2);
	printf("\nafter list:\n");
	print_lst(list);
	printf("\nafter list2:\n");
	print_lst(list2);
	free_list(list);
	free_list(list2);
	atexit(my_leaks);
	return (0);
}
