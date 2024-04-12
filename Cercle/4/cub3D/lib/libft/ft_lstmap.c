/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:42:32 by alfloren          #+#    #+#             */
/*   Updated: 2023/11/10 15:42:00 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*map;
	t_list	*first;

	if (!f || !del)
		return (NULL);
	first = NULL;
	while (lst)
	{
		map = ft_lstnew((*f)(lst->content));
		if (!map)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		else
		{
			ft_lstadd_back(&first, map);
			lst = lst->next;
		}
	}
	return (first);
}

	// if (lst)
	// {
	// 	map = ft_lstnew(lst->content);
	// 	map->next = lst->next;
	// 	lst = lst->next;
	// 	first = map;
	// 	if (!first && del)
	// 	{
	// 		ft_lstclear(&first, del);
	// 		return (NULL);
	// 	}
	// }
