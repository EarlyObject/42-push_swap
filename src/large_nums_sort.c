/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   large_nums_sort.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:54:11 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/06 12:35:50 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void printArray(int arr[], int n)
{
	int	i;
	for (i = 0; i < n; i++)
		printf("%d \n", arr[i]);
	printf("\n");
}

int *
	cplst_to_arr(t_list *const *lst, int size)
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

int
	get_chunks_num(int size)
{
	int	chunks_num;

	if (size > 100 && size <= 500)
		return (11);
	chunks_num = size / 20;
	if (chunks_num < 1)
		chunks_num = 1;
	else if (size % 20 != 0)
		chunks_num += 1;
	return (chunks_num);
}

void
	sort_hundred(t_list **stack_a)
{
	int		size;
	double	chunks;
	int		i;
	int		j;
	int		last;
	int		*arr;
	t_list	*stack_b;
	t_list	*temp;
/*	int 	pos_from_top;
	int 	pos_from_bottom;*/

	size = ft_lstsize(*stack_a);
	chunks = get_chunks_num(size);
	arr = cplst_to_arr(stack_a, size);
	ft_insertion_sort(arr, size);
	stack_b = (t_list *)malloc(sizeof(t_list));
	stack_b->content = NULL;
	stack_b->next = NULL;
	i = 0;
	while (i < chunks)
	{
		j = i * 10;
		last = j + 19;
		if (i == (chunks - 1) && (size % 20 != 0))
			last = (size % 20) - 1;
		int count;
		count = j;
		while (count <= last)
		{
			temp = *stack_a;
			int up_pos;
			int low_pos;
			int low;
			int high;
			int k;
			int up_val;
			int low_val;
			bool move_down;

			up_pos = -1;
			k = 0;
			low = arr[j];
			high = arr[last];
			move_down = true;
			while (temp)
			{
				if (cont_of(temp) >= low && cont_of(temp) <= high)
				{
					if (up_pos < 0)
					{
						up_pos = k;
						up_val = cont_of(temp);
					}
					low_pos = k;
					low_val = cont_of(temp);
				}
				k++;
				temp = temp->next;
			}
			if (up_pos < ft_lstsize(*stack_a) - low_pos) //add for if donor_val is int_max
				prepare_place(up_val - 1, stack_a, 'a');
			else
				prepare_place(low_val - 1, stack_a, 'a');

			//sort stack b for putting from stack a
			if (up_pos < ft_lstsize(*stack_a) - low_pos)
				prepare_place(cont_of(*stack_a), &stack_b, 'a');
			else
				prepare_place(cont_of(*stack_a), &stack_b, 'a');
			pb(stack_a, &stack_b);
			while (!is_sorted(stack_b))
				iterate_lst(&stack_b, 'b');
			count++;
		}
		i++;
	}
	while (stack_b)
	{
		prepare_place_ascending(cont_of(stack_b), stack_a, 'b');
		pa(stack_a, &stack_b);
	}
	while (!is_sorted(*stack_a))
		iterate_lst(stack_a, 'a');
	printf("stack a :\n");
	print_lst(*stack_a);
	printf("***\n");
	free(arr);
	free_list(stack_b);
}
