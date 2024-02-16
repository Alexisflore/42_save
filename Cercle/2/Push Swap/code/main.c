/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:46:03 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 20:04:30 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <stdio.h>

char	**ft_args(int ac, char **av)
{
	char	**args;
	char	*arg1;
	char	*arg2;
	int		i;

	if (ac == 2)
		return (args = ft_split(av[1], ' '), args);
	arg2 = (char *)malloc(1);
	if (arg2 == NULL)
		exit(EXIT_FAILURE);
	arg2[0] = 0;
	i = 1;
	while (i < ac)
	{
		arg1 = ft_joinspace(av[i], " ");
		arg2 = ft_strjoin(arg2, arg1);
		i++;
	}
	args = ft_split(arg2, ' ');
	free(arg2);
	return (args);
}

t_list	***init_stack(char **args)
{
	t_list		**stack_a;
	t_list		**stack_b;
	int			i;
	t_list		*new;
	t_list		***stacks;

	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	stacks = (t_list ***)malloc(sizeof(t_list **) * 2);
	*stack_b = NULL;
	*stack_a = NULL;
	i = -1;
	while (args[++i])
	{
		new = ft_lstnew(ft_atoi(args[i]));
		ft_lstadd_back(stack_a, new);
	}
	index_stack(stack_a, -2147483648, -1);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		exit(0);
	}
	return (stacks[0] = stack_a, stacks[1] = stack_b, stacks);
}

// void	printlist(t_list *head)
// {
// 	t_list	*tmp;

// 	tmp = head;
// 	while (tmp != NULL)
// 	{alexisflorentin14@gmail.com
// 		ft_putendl_fd("value : ", 1);
// 		ft_putnbr_fd(tmp->value, 1);
// 		ft_putendl_fd("\n", 1);
// 		tmp = tmp->next;
// 	}
// }

int	main(int ac, char **av)
{
	char		**args;
	t_list		***stacks;

	if (ac < 2)
		return (0);
	args = ft_args(ac, av);
	check_args(args);
	stacks = init_stack(args);
	ft_free(args);
	sort(stacks);
	free_stacks(stacks);
	return (0);
}


