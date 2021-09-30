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

void
	build_lst(char *const *argv, t_list **list)
{
	int	i;
	int	*pnum;

	i = 0;
	while (argv[i])
	{
		pnum = (int *)malloc(sizeof(int));
		*pnum = ft_atoi_modf(argv[i]);
		ft_lstadd_back(list, ft_lstnew(pnum));
		i++;
	}
}

void
	free_list(t_list *list)
{
	t_list	*temp;

	while (list)
	{
		temp = list->next;
		free(list->content);
		free(list);
		list = temp;
	}
}

void
	free_2d_arr(void **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

int
	main(int argc, char *argv[])
{
	t_list	*lst;
	int		i;
	char	**arg_array;
	void	**p;

	if (argc < 2)
		exit(0);
	lst = NULL;
	i = 1;
	while (i < argc)
	{
		arg_array = ft_split(argv[i], ' ');
		build_lst(arg_array, &lst);
		p = (void**)arg_array;
		free_2d_arr(p);
		i++;
	}
	if (!is_ordered(lst))
		sort_lst(&lst);


	//build_lst(argv, &lst);
	//printf("\ninitial lst:\n");
	//print_lst(lst);
	//sa(&lst);
	//printf("\nafter ist:\n");
	//print_lst(lst);
	free_list(lst);
	atexit(my_leaks);
	return (0);
}
