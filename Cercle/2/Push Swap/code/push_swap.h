/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:47:59 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 18:37:12 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

void	ft_errors(int x);
void	sort(t_list ***stacks);
void	free_stacks(t_list ***stacks);
void	ft_free(char **str);
void	free_stack(t_list **stack);
void	sortx(t_list **stack_a, t_list **stack_b);
int		is_sorted(t_list **stack);
int		rotate(t_list **stacks);
int		g_distance(t_list **stack, int index);
int		g_min(t_list **stack, int val);
int		max_bit(t_list **stack);
int		is_number(char *nbr);
int		is_max(char *nbr);
int		double_nbr(int num, char **args, int i);
int		ft_more(t_list **stack);
int		get_new_min(t_list **stack, int min);
void	index_stack(t_list **stack, int min, int index);
int		swap(t_list **stack);
int		reverse_rotate(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
void	sort(t_list ***stacks);
int		rrr(t_list ***stacks);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		pb(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
char	**ft_args(int ac, char **av);
t_list	***init_stack(char **args);
void	sort_n(t_list **stack_a, t_list **stack_b, int n, int distance);
void	sort3(t_list **stack_a);
void	step1(t_list **stack_a);
void	last_step(t_list **stack_a);
int		check_args(char **args);
#endif
