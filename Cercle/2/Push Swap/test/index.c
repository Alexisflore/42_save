/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 13:22:24 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/06 14:07:47 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_more(t_list **stack)
{
	t_list	*head;

	head = *stack;
	while (head)
	{
		if (head->index == -1)
			return (1);
		head = head->next;
	}
	return (0);
}

int	get_new_min(t_list **stack, int min)
{
	t_list	*head;
	int		new_min;

	head = *stack;
	new_min = 2147483647;
	while (head)
	{
		if (head->value == -2147483648 && head->index == -1)
			return (min);
		if (head->value > min && head->value < new_min)
			new_min = head->value;
		head = head->next;
	}
	return (new_min);
}

void	index_stack(t_list **stack, int min, int index)
{
	t_list	*head;

	if (!ft_more(stack))
		return ;
	head = *stack;
	min = get_new_min(stack, min);
	while (head)
	{
		if (head->value == min)
		{
			index++;
			head->index = index;
			index_stack(stack, min, index);
		}
		head = head->next;
	}
}

// int main() {
//     // Création d'une liste chainée de test
//    t_list* node1 = malloc(sizeof(t_list));
//    t_list* node2 = malloc(sizeof(t_list));
//    t_list* node3 = malloc(sizeof(t_list));

//     // Initialisation des valeurs
//     node1->value = 10;
//     node2->value = 5;
//     node3->value = 15;

//     // Initialisation des index à -1
//     node1->index = -1;
//     node2->index = -1;
//     node3->index = -1;

//     // Liaison des nœuds
//     node1->next = node2;
//     node2->next = node3;
//     node3->next = NULL;

//     // Appel de la fonction index_stack
//     index_stack(&node1, -8888, -1);

//     // Affichage des résultats
//    t_list* current = node1;
//     while (current) {
//         printf("Value: %d, Index: %d\n", current->value, current->index);
//         current = current->next;
//     }

//     // Libération de la mémoire
//     free(node1);
//     free(node2);
//     free(node3);

//     return 0;
// }
