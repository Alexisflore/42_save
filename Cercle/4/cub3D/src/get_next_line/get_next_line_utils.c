/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 15:29:34 by alfloren          #+#    #+#             */
/*   Updated: 2024/04/10 16:24:26 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_lstadd_back(t_list **stash, char *buf, int count)
{
	int		i;
	t_list	*new;

	i = 0;
	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->next = NULL;
	new->content = malloc(sizeof(char) * (count + 1));
	if (!new->content)
		return ;
	while (buf[i] && i < count)
	{
		new->content[i] = buf[i];
		i++;
	}
	new->content[i] = '\0';
	if (!(*stash))
	{
		*stash = new;
		return ;
	}
	gnl_lstlast(*stash)->next = new;
}

t_list	*gnl_lstlast(t_list *lst)
{
	t_list	*current;

	current = lst;
	while (current && current->next)
		current = current->next;
	return (current);
}

void	generate_line(char **line, t_list *stash)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i] && stash->content[i] != '\n')
		{
			len++;
			i++;
		}
		if (stash->content[i] == '\n')
		{
			len++;
			break ;
		}
		stash = stash->next;
	}
	(*line) = malloc(sizeof(char) * (len + 1));
}

int	foundnewline(t_list *stash)
{
	int		i;
	t_list	*last;

	i = 0;
	if (!stash)
		return (0);
	last = gnl_lstlast(stash);
	while (last->content[i])
	{
		if (last->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	free_stash(t_list *stash)
{
	t_list	*next;

	while (stash)
	{
		free((stash)->content);
		next = (stash)->next;
		free(stash);
		stash = next;
	}
}
