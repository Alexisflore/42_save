/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortx.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:14:23 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 18:26:19 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_bit(t_list **stack)
{
	t_list	*node;
	int		max;
	int		max_bit;

	node = *stack;
	max = node->index;
	max_bit = 0;
	while (node)
	{
		if (node->index > max)
			max = node->index;
		node = node->next;
	}
	while ((max >> max_bit) != 0)
		max_bit++;
	return (max_bit);
}

// void	printlist(t_list *head)
// {
// 	t_list	*tmp;

// 	tmp = head;
// 	while (tmp != NULL)
// 	{
// 		ft_putendl_fd("value: ", 1);
// 		ft_putnbr_fd(tmp->value, 1);
// 		tmp = tmp->next;
// 	}
// }

void	sortx(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	int		i;
	int		j;
	int		size;
	int		max_bits;

	// printlist(*stack_a);
	i = 0;
	size = ft_lstsize(*stack_a);
	max_bits = max_bit(stack_a);
	node = *stack_a;
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			node = *stack_a;
			if (((node->index >> i) & 1) == 1)
				ra(stack_a);
			else
			{
				pb(stack_a, stack_b);
				// printlist(*stack_b);
				// printf("%d", j);
			}
		}
		while (ft_lstsize(*stack_b) != 0)
		{
			pa(stack_a, stack_b);
		}
		i++;
	}
}
