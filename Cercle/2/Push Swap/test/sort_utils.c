/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 18:48:31 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 17:39:49 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
		free(str[i--]);
}

void	free_stacks(t_list ***stacks)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	i = 0;
	while (i < 2)
	{
		head = *stacks[i];
		while (head)
		{
			tmp = head;
			head = head->next;
			free(tmp);
		}
		free(stacks[i]);
		i++;
	}
}

void	free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;
	int		i;

	head = *stack;
	i = 0;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
	i++;
}

void	sort(t_list ***stacks)
{
	int	size;
	int	distance;

	distance = g_distance(stacks[0], g_min(stacks[0], -1));
	size = ft_lstsize(*stacks[0]);
	ft_putnbr_fd(size, 1);
	if (is_sorted(stacks[0]) || size == 0
		|| size == 1)
		return ;
	else if (size == 2)
		sa(stacks[0]);
	else if (size <= 5)
		sort_n(stacks[0], stacks[1], size, distance);
	else
		sortx(stacks[0], stacks[1]);
}

int	is_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->value > head->next->value)
			return (0);
		head = head->next;
	}
	return (1);
}
