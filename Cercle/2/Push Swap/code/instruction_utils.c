/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:41:48 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 18:31:51 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_val;
	int		tmp_index;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	next = head->next;
	if (!head && !next)
		exit(0);
	tmp_val = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_val;
	next->index = tmp_index;
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	tail->next = head;
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*head;
	t_list	*tail;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	tail = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	tail->next = *stack;
	*stack = tail;
	return (0);
}

int	push(t_list **stack_to, t_list **stack_from)
{
	t_list	*tmp;
	t_list	*head_to;
	t_list	*head_from;

	if (ft_lstsize(*stack_from) == 0)
		return (-1);
	head_to = *stack_to;
	head_from = *stack_from;
	tmp = head_from;
	head_from = head_from->next;
	*stack_from = head_from;
	if (!head_to)
	{
		head_to = tmp;
		head_to->next = NULL;
		*stack_to = head_to;
	}
	else
	{
		tmp->next = head_to;
		*stack_to = tmp;
	}
	return (0);
}

int	rrr(t_list ***stacks)
{
	if ((ft_lstsize(*stacks[0]) < 2) || (ft_lstsize(*stacks[1]) < 2))
		return (-1);
	reverse_rotate(stacks[0]);
	reverse_rotate(stacks[1]);
	ft_putendl_fd("rrr", 1);
	return (0);
}
// int ft_lstsize(t_list* lst) {
//     int size = 0;
//     while (lst) {
//         size++;
//         lst = lst->next;
//     }
//     return size;
// }

// // Fonction pour trouver le dernier élément d'une liste
// t_list* ft_lstlast(t_list* lst) {
//     if (!lst)
//         return NULL;
//     while (lst->next) {
//         lst = lst->next;
//     }
//     return lst;
// }

// int main() {
//     // Création d'une liste chaînée de test
//     t_list* node1 = malloc(sizeof(t_list));
//     t_list* node2 = malloc(sizeof(t_list));
// 	t_list* node3 = malloc(sizeof(t_list));

//     // Initialisation des valeurs
//     node1->value = 10;
//     node2->value = 5;
// 	node3->value = 6;
//     // Liaison des nœuds
//     node1->next = node2;
//     node2->next = node3;
// 	node3->next = NULL;

//     // Création d'un tableau de pointeurs vers la liste
//     t_list** stacks = malloc(sizeof(t_list*));
//     *stacks = node1;

//     // Appel de la fonction rotate
//     int result = reverse_rotate(stacks);

//     // Affichage des résultats
//     t_list* current = stacks[0];
//     while (current) {
//         printf("Value: %d, Index: %d\n", current->value, current->index);
//         current = current->next;
//     }

//     // Libération de la mémoire
//     free(node1);
//     free(node2);
// 	free(node3);
//     free(stacks);

//     return 0;
// }
