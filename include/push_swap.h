/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asydykna <asydykna@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 10:21:04 by asydykna          #+#    #+#             */
/*   Updated: 2021/10/06 12:35:20 by asydykna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <limits.h>
# include <stdbool.h>
# include "../libft/libft.h"

void	swap_two(t_list **lst);
void	top_to_bottom(t_list **lst);
void	bottom_to_top(t_list **lst);
void	put_to_other_stack(t_list **donor, t_list **recipient);
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
void	pa(t_list **recipient, t_list **donor);
void	pb(t_list **donor, t_list **recipient);
void	sort_lst(t_list **lst);
int		is_sorted(t_list *lst);
int		is_reverse_sorted(t_list *lst);
int		cont_of(t_list *lst);
double	get_max(t_list **lst);
double	get_min(t_list **lst);
void	free_list(t_list *list);
double	get_max(t_list **lst);
int		top_bgst_then_sorted(t_list **lst);
void	iterate_lst(t_list **lst, char stack_name);
int		calc_steps(int steps, t_list *recipient, int target);
void
prepare_place(int donor_val, t_list **recipient, char donor_name, bool sort_rcpt_ascending);
void	prepare_place_ascending(int donor_val, t_list **recipient, char donor_name); //needs refactoring
void	sort_others(t_list **stack_a);
void	ft_error_exit(char *err_message, int num, int exit_code);
void	duplicate_check(int num, t_list *lst);
int		get_chunks(int size);
int		get_optimum(int size);
int		*cp_lst_to_arr(t_list *const *lst, int size);
bool	is_ordered_not_sorted(t_list *lst);
t_list	*make_lst(void );

#endif 