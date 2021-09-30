/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:21:04 by asydykna          #+#    #+#             */
/*   Updated: 2021/09/27 10:39:41 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include "../libft/libft.h"

void	swap_two(t_list **lst);
void	top_to_bottom(t_list **lst);
void	bottom_to_top(t_list **lst);
void	put_to_other_stack(t_list **a, t_list **b);
void	print_lst(t_list *lst);
void	sa(t_list **lst);
void	sb(t_list **lst);
void	ss(t_list **a, t_list **b);
void	ra(t_list **lst);
void	rb(t_list **lst);
void	rr(t_list **a, t_list **b);
void	rra(t_list **lst);
void	rrb(t_list **lst);
void	rrr(t_list **a, t_list **b);
void	pa(t_list **a, t_list **b);
void	pb(t_list **a, t_list **b);
void	sort_lst(t_list **lst);
void	perrorexit(void);
int		is_ordered(t_list *lst);
int		cont_of(t_list *lst);

#endif 