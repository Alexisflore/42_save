/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 15:46:03 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 18:25:26 by alfloren         ###   ########.fr       */
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
	else
	{
		arg2 = (char *)malloc(sizeof(char));
		arg2[0] = 0;
		i = 1;
		while (i < ac)
		{
			arg1 = ft_strjoin(av[i], " ");
			arg2 = ft_strjoin(arg2, arg1);
			free(arg1);
			i++;
		}
		printf("Concatenated string: \"%s\"\n", arg2);
		args = ft_split(arg2, ' ');
		free(arg2);
		return (args);
	}
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

void	printlist(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putendl_fd("value : ", 1);
		ft_putnbr_fd(tmp->value, 1);
		ft_putendl_fd("\n", 1);
		tmp = tmp->next;
	}
}

int	main(int ac, char **av)
{
	char		**args;
	t_list		***stacks;

	if (ac < 2)
		return (0);
	args = ft_args(ac, av);
	check_args(ac, args);
	stacks = init_stack(args);
	sort(stacks);
	printlist(*stacks[0]);
	free_stacks(stacks);
	return (0);
}

// void print_stack(t_list *stack, const char *name)
// {
//     printf("%s: ", name);
//     while (stack)
//     {
//         printf("%d ", *(int *)stack->content);
//         stack = stack->next;
//     }
//     printf("\n");
// }

// int main(int ac, char **av)
// {
//     if (ac < 2)
//         return 0;

//     char **args = ft_args(ac, av);
//     // check_args(ac, args);

//     t_list ***stacks = init_stack(args);

//     // Print the initial state of stacks
//     print_stack(stacks[0], "Stack A");
//     print_stack(stacks[1], "Stack B");

//     // Perform operations with stacks if needed

//     // // Free allocated memory
//     // free_stack(stacks[0]); // stack_a
//     // free_stack(stacks[1]); // stack_b
//     // free(stacks);

//     return 0;
// }
