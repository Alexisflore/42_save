/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:25 by alfloren          #+#    #+#             */
/*   Updated: 2024/04/12 11:25:29 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

// typedef struct g_list
// {
// 	char			*content;
// 	struct g_list	*next;
// }				g_list;

void	gnl_lstadd_back(t_list **lst, char *buf, int count);

t_list	*gnl_lstlast(t_list *lst);

int		foundnewline(t_list *stash);

void	free_stash(t_list *stash);

void	generate_line(char **line, t_list *stash);

int		gnl_strlen(char *str);

void	read_and_stach(t_list **stash, int fd);

void	extract_line(t_list *stash, char **line);

void	clean_stash(t_list **stash);

char	*get_next_line(int fd);
#endif
