/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 10:48:41 by alfloren          #+#    #+#             */
/*   Updated: 2024/04/14 11:47:41 by macbookpro       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*get_next_line(int fd, bool free_static)
{
	static t_list	*stash = NULL;
	char			*line;

	if (free_static == true)
	{
		free_stash(stash);
		stash = NULL;
		return (NULL);
	}
	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	read_and_stach(&stash, fd);
	if (!stash)
		return (NULL);
	extract_line(stash, &line);
	clean_stash(&stash);
	if (line[0] == '\0')
	{
		free_stash(stash);
		stash = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}

// read and stash
void	read_and_stach(t_list **stash, int fd)
{
	char	*buf;
	int		count;

	count = 1;
	while (!foundnewline(*stash) && count != 0)
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		count = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && count == 0) || count == -1)
		{
			free(buf);
			return ;
		}
		buf[count] = '\0';
		gnl_lstadd_back(stash, buf, count);
		free(buf);
	}
}

//extract line
void	extract_line(t_list *stash, char **line)
{
	int	i;
	int	j;

	if (!stash)
		return ;
	generate_line(line, stash);
	if (!(*line))
		return ;
	i = 0;
	while (stash)
	{
		j = 0;
		while (stash->content[j] && stash->content[j] != '\n')
			(*line)[i++] = stash->content[j++];
		if (stash->content[j] == '\n')
		{
			(*line)[i++] = stash->content[j];
			break ;
		}
		stash = stash->next;
	}
	(*line)[i] = '\0';
}

// clean
void	clean_stash(t_list **stash)
{
	t_list	*last;
	t_list	*next_stash;
	int		i;
	int		j;

	j = 0;
	i = 0;
	next_stash = malloc(sizeof(t_list) * 1);
	if (!next_stash)
		return ;
	last = gnl_lstlast(*stash);
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	next_stash->content
		= malloc(sizeof(char) * (gnl_strlen(last->content) - i + 1));
	next_stash->next = NULL;
	if (!next_stash->content)
		return ;
	while (last->content[i])
		next_stash->content[j++] = last->content[i++];
	next_stash->content[j] = '\0';
	free_stash(*stash);
	*stash = next_stash;
}

int	gnl_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
// #include <stdio.h>
// #include <sys/types.h>
// #include <sys/stat.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd;
// 	char	*line;
// 	int		i;

// 	fd = open("get_next_line.h", O_RDONLY);
// 	if (fd < 0)
// 		return (1);
// 	i = 1;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 		{
// 			i = 0;
// 			// printf("PLUS DE RESULTAT\n");
// 			free(line);
// 			break ;
// 		}
// 		printf("%s", line);
// 		free(line);
// 		i++;
// 	}
// 	return (0);
// }
