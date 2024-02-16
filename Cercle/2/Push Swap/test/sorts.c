/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorts.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:02:36 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/06 18:54:16 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_n(t_list **stack_a, t_list **stack_b, int n, int distance)
{
	if (n == 3)
	{
		sort3(stack_a);
		return ;
	}
	if (distance == 1)
		ra(stack_a);
	else if (distance == 2)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (distance == 3)
	{
		rra(stack_a);
		if (n == 5)
			rra(stack_a);
	}
	else if (n == 5 && distance == 4)
		rra(stack_a);
	if (is_sorted(stack_a))
		return ;
	pb(stack_a, stack_b);
	sort_n(stack_a, stack_b, n - 1, g_distance(stack_a, g_min(stack_a, -1)));
	pa(stack_a, stack_b);
}

void	sort3(t_list **stack_a)
{
	t_list	*head;
	int		min;
	int		next_min;

	head = *stack_a;
	min = g_min(stack_a, -1);
	next_min = g_min(stack_a, min);
	if (is_sorted(stack_a))
		return ;
	if (head->index == min && head->next->index != next_min)
		step1(stack_a);
	else if (head->index == next_min)
	{
		if (head->next->index == min)
			sa(stack_a);
		else
			rra(stack_a);
	}
	else
	{
		if (head->next->index == min)
			ra(stack_a);
		else
			last_step(stack_a);
	}
}

void	step1(t_list **stack_a)
{
	ra(stack_a);
	sa(stack_a);
	rra(stack_a);
}

void	last_step(t_list **stack_a)
{
	sa(stack_a);
	rra(stack_a);
}
