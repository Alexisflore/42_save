/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 12:42:17 by ladloff           #+#    #+#             */
/*   Updated: 2024/02/12 10:32:59 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include "minishell.h"
#include "libft.h"

void	free_environment_list(t_env *env)
{
	t_env	*current;
	t_env	*next;

	current = env;
	while (current)
	{
		next = current->next;
		free(current->name);
		free(current->value);
		free(current);
		current = next;
	}
}

static void	create_add_env_node(t_master *master, char *name, char *value,
	t_env **env_list)
{
	t_env	*new_node;

	new_node = malloc(sizeof(t_env));
	if (!new_node)
	{
		free(name);
		free(value);
		error_exit(master, "malloc (create_add_env_node)", false);
		return ;
	}
	new_node->name = name;
	new_node->value = value;
	new_node->next = NULL;
	if (!*env_list)
	{
		*env_list = new_node;
		(*env_list)->last = new_node;
	}
	else
	{
		(*env_list)->last->next = new_node;
		(*env_list)->last = new_node;
	}
}

static void	manage_pwd(t_master *master, t_env **env_list)
{
	char	*cwd;
	char	*name;

	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		perror("getcwd (manage_empty_environment)");
		exit(EXIT_FAILURE);
	}
	name = ft_strdup("PWD");
	if (!name)
	{
		free(cwd);
		perror("ft_strdup (manage_empty_environment)");
		exit(EXIT_FAILURE);
	}
	create_add_env_node(master, name, cwd, env_list);
}

static void	manage_empty_environment(t_master *master, t_env **env_list)
{
	char	*name;
	char	*value;

	manage_pwd(master, env_list);
	name = ft_strdup("SHLVL");
	value = ft_strdup("1");
	if (!name || !value)
	{
		free(name);
		free(value);
		ft_error_exit(master, "ft_strdup manage empty env", ENOMEM, false);
		return ;
	}
	create_add_env_node(master, name, value, env_list);
	name = ft_strdup("_");
	value = ft_strdup("minishell");
	if (!name || !value)
	{
		free(name);
		free(value);
		ft_error_exit(master, "ft_strdup manage empty env", ENOMEM, false);
		return ;
	}
	create_add_env_node(master, name, value, env_list);
}

void	manage_environment(t_master *master, t_env **env_list)
{
	char		*name;
	char		*value;
	extern char	**environ;
	char		*equals_location;

	if (!*environ)
		manage_empty_environment(master, env_list);
	while (*environ)
	{
		equals_location = ft_strchr(*environ, '=');
		name = ft_strndup(*environ, equals_location - *environ);
		if (!name)
			ft_error_exit(master, "ft_strndup manage_env", ENOMEM, false);
		value = ft_strdup(equals_location + 1);
		if (!value)
		{
			free(name);
			ft_error_exit(master, "ft_strdup manage_env", ENOMEM, false);
			return ;
		}
		if (!ft_strcmp(name, SHLVL))
			value = update_shlvl(master, value, name);
		create_add_env_node(master, name, value, env_list);
		environ++;
	}
}
