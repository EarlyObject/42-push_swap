/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:20:49 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/28 10:03:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int
	main(int argc, char *argv[])
{
	int		i;
	t_list	*list;
	char	*content;

	i = 1;
	list = NULL;
	content = NULL;
	while (argv[i])
	{
		printf("adding %s\n", argv[i]);
		ft_lstadd_front(&list, ft_lstnew(argv[i]));
		i++;
	}
	printf("argc number = %d\n", argc);
	while (list)
	{
		content = list->content;
		printf("%s\n", content);
		list = list->next;
	}
	return (0);
}
