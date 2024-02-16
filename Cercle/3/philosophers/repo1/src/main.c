/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 16:02:07 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/22 09:48:09 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/philo.h"

int	one_philo(t_data *data)
{
	data->start_time = get_time();
	if (pthread_create(&data->tid[0], NULL, &routine, &data->philos[0]))
		return (error("Thread error", data));
	pthread_detach(data->tid[0]);
	while (data->dead == 0)
		ft_usleep(0);
	ft_exit(data);
	return (0);
}

void	clear_data(t_data	*data)
{
	if (data->tid)
		free(data->tid);
	if (data->forks)
		free(data->forks);
	if (data->philos)
		free(data->philos);
}

void	ft_exit(t_data *data)
{
	int	i;

	i = -1;
	while (++i < data->philo_num)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].lock);
	}
	pthread_mutex_destroy(&data->write);
	pthread_mutex_destroy(&data->lock);
	clear_data(data);
}

int	error(char *str, t_data *data)
{
	printf("%s\n", str);
	if (data)
		ft_exit(data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		error("False number of inputs", NULL);
		return (1);
	}
	if (input_checker(argv))
		return (1);
	if (init(&data, argv, argc))
		return (1);
	if (data.philo_num == 1)
		return (one_philo(&data));
	if (thread_init(&data))
		return (1);
	ft_exit(&data);
	return (0);
}

// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	sum = 0;
// 	i = 0;
// 	if (!s)
// 		return (-1);
// 	if (s[i] != c && s[i] && s)
// 	{
// 		sum++;
// 		i++;
// 	}
// 	while (s[i] && s)
// 	{
// 		if (s[i] != c && s[i - 1] == c)
// 			sum++;
// 		i++;
// 	}
// 	return (sum);
// }

// int	longword(const char *s, char c)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] && s[i] != c)
// 		i++;
// 	return (i);
// }

// char	**free_split(char **split)
// {
// 	int	i;

// 	i = -1;
// 	if (split)
// 	{
// 		while (split[++i])
// 			free(split[i]);
// 		free(split);
// 	}
// 	return (NULL);
// }

// char	**ft_split(char const *s, char c)
// {
// 	size_t		i;
// 	size_t		j;
// 	size_t		k;
// 	char		**split;

// 	split = malloc(sizeof(char *) * (countwords(s, c) + 1));
// 	if (!split || !s)
// 		return (NULL);
// 	i = -1;
// 	k = 0;
// 	while (++i < ft_strlen(s))
// 	{
// 		if (s[i] != c)
// 		{
// 			split[k] = malloc(sizeof(char) * (1 + longword(s + i, c)));
// 			if (!split[k])
// 				return (free_split(split));
// 			j = 0;
// 			while (s[i] != c && s[i])
// 				split[k][j++] = s[i++];
// 			split[k++][j] = 0;
// 		}
// 	}
// 	split[k] = NULL;
// 	return (split);
// }
