/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large_nums.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 10:54:11 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/07 15:52:13 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void
	calc_ups_lows(const int *arr, t_list *tmp, const int idxs[],
				  int *ups_and_lows)
{
	int		i;
	int		first_idx;
	int		last_idx;

	i = 0;
	first_idx = idxs[0];
	last_idx = idxs[1];
	while (tmp)
	{
		if (cont_of(tmp) >= arr[first_idx] && cont_of(tmp) <= arr[last_idx])
		{
			if (ups_and_lows[0] < 0)
			{
				ups_and_lows[0] = i;
				ups_and_lows[1] = cont_of(tmp);
			}
			ups_and_lows[2] = i;
			ups_and_lows[3] = cont_of(tmp);
		}
		i++;
		tmp = tmp->next;
	}
}

int
	get_correct_val(int val)
{
	if (val == -2147483648 || val == 2147483647)
		return (val);
	else
		return (val - 1);
}

void
	sort_and_push_chunks(t_list **stack_a, t_list **stack_b, const int *arr,
						 int idxs[])
{
	t_list	*tmp;
	int		count;
	int		first_idx;
	int		last_idx;
	int		ups_and_lows[4];

	first_idx = idxs[0];
	last_idx = idxs[1];
	count = first_idx;
	while (count <= last_idx)
	{
		tmp = *stack_a;
		ups_and_lows[0] = -1;
		calc_ups_lows(arr, tmp, idxs, ups_and_lows);
		if (ups_and_lows[0] < ft_lstsize(*stack_a) - ups_and_lows[2]) //add for if donor_val is int_max
			prepare_place(get_correct_val(ups_and_lows[1]), stack_a, 'b', 0);
		else
			prepare_place(get_correct_val(ups_and_lows[3]), stack_a, 'b', 0);
		prepare_place(cont_of(*stack_a), stack_b, 'a', true);
		pb(stack_a, stack_b);
		count++;
	}
}

void
	fill_and_sort_stackb(t_list **stack_a, t_list **stack_b, int size,
						 const int *arr)
{
	double	chunks;
	int		i;
	int		first_idx;
	int		last_idx;
	int		idxs[2];

	chunks = get_chunks(size);
	i = 0;
	while (i < chunks)
	{
		first_idx = i * get_optimum(size);
		last_idx = first_idx + (get_optimum(size) - 1);
		if (i == (chunks - 1) && (size % get_optimum(size) != 0))
			last_idx = first_idx + (size % get_optimum(size)) - 1;
		idxs[0] = first_idx;
		idxs[1] = last_idx;
		sort_and_push_chunks(stack_a, stack_b, arr, idxs);
		i++;
	}
}

void
	sort_others(t_list **stack_a)
{
	int		size;
	int		*arr;
	t_list	*stack_b;

	size = ft_lstsize(*stack_a);
	arr = cp_lst_to_arr(stack_a, size);
	ft_insertion_sort(arr, size);
	stack_b = make_lst();
	fill_and_sort_stackb(stack_a, &stack_b, size, arr);
	while (stack_b)
	{
		prepare_place(cont_of(stack_b), stack_a, 'b', true);
		pa(stack_a, &stack_b);
	}
	while (!is_sorted(*stack_a))
		iterate_lst(stack_a, 'a');
	free(arr);
	free_list(stack_b);
}
