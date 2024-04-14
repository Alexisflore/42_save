/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ladloff <ladloff@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 19:18:28 by macbookpro        #+#    #+#             */
/*   Updated: 2024/04/14 02:59:06 by ladloff          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	t_map_add_back(t_map **alst, t_map *new)
{
	t_map	**tmp;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	tmp = alst;
	while ((*tmp)->next != NULL)
		tmp = &(*tmp)->next;
	(*tmp)->next = new;
}

int	size_x(t_map *map)
{
	int		size;
	t_map	*tmp;

	tmp = map;
	size = 0;
	while (tmp != NULL)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

int	max_size(t_data *data, t_path *path, t_map *map)
{
	int		max;
	t_map	*tmp;

	if (map == NULL)
		error_path(data, path, "Error\nEmpty map\n");
	tmp = map;
	max = 0;
	while (tmp->next != NULL)
	{
		if (tmp->size > max)
			max = tmp->size;
		tmp = tmp->next;
	}
	return (max);
}

void	next_data(t_path *path, int fd)
{
	free(path->line);
	path->line = get_next_line(fd);
}

void	fill_rgb(t_data *data, t_path *path, t_rgb **rgb)
{
	check_nbr(data, path->rgb[0], path, &(*rgb)->r);
	check_nbr(data, path->rgb[1], path, &(*rgb)->g);
	check_nbr(data, path->rgb[2], path, &(*rgb)->b);
}
