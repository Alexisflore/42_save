/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:52:25 by alfloren          #+#    #+#             */
/*   Updated: 2023/11/14 19:18:09 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}				t_list;

void	ft_lstadd_back(t_list **lst, char *buf, int count);

t_list	*ft_lstlast(t_list *lst);

int		foundnewline(t_list *stash);

void	free_stash(t_list *stash);

void	generate_line(char **line, t_list *stash);

int		ft_strlen(char *str);

void	read_and_stach(t_list **stash, int fd);

void	extract_line(t_list *stash, char **line);

void	clean_stash(t_list **stash);

char	*get_next_line(int fd);
#endif
