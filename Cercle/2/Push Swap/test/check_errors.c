/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alfloren <alfloren@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:43:27 by alfloren          #+#    #+#             */
/*   Updated: 2023/12/07 18:26:43 by alfloren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

int	is_number(char *nbr)
{
	int	i;

	i = 0;
	if (nbr[0] == '-' || nbr[0] == '+')
		i++;
	while (nbr[i])
	{
		if (!ft_isdigit(nbr[i]))
			return (0);
		i++;
	}
	return (1);
}

int	is_max(char *nbr)
{
	int	i;

	i = 0;
	if ((nbr[0] == '+' || nbr[0] == '-'))
		i++;
	while (nbr[i])
	{
		if (nbr[i] != '0')
			return (1);
		i++;
	}
	return (0);
}

int	double_nbr(int num, char **args, int i)
{
	i++;
	while (args[i])
	{
		if (ft_atoi(args[i]) == num)
			return (0);
		i++;
	}
	return (0);
}

int	check_args(int ac, char **args)
{
	int		i;

	i = 0;
	ac = 3;
	while (args[i])
	{
		if (!is_number(args[i])
			|| (ft_atoi(args[i]) == 0 && is_max(args[i]))
			|| double_nbr(ft_atoi(args[i]), args, i))
		{
			write(1, "Error", 5);
			exit(0);
		}
		i++;
	}
	return (1);
}

// int main()
// {
//     // Test is_number function
//     char *num1 = "123";
//     char *num2 = "-456";
//     char *num3 = "0";
//     char *notNum = "abc";

//     printf("%s is a number: %d\n", num1, is_number(num1));
//     printf("%s is a number: %d\n", num2, is_number(num2));
//     printf("%s is a number: %d\n", num3, is_number(num3));
//     printf("%s is a number: %d\n", notNum, is_number(notNum));

//     // Test is_max function
//     char *max1 = "2147483647";
//     char *max2 = "-2147483648";
//     char *notMax = "0";

//     // printf("%s is max: %d\n", max1, is_max(max1));
//     // printf("%s is max: %d\n", max2, is_max(max2));
//     printf("%s is max: %d\n", notMax, is_max(notMax));

//     return 0;
// }
// int	main(int ac, char **av)
// {
// 	int j;
// 	j = '0';
// 	while (j++ < 5 + '0')
// 	{
// 		write(1, &j, 1);
// 		write(1, "\n", 1);
// 	}
// 	return (0);
// }

// (ft_atoi(args[i]) == 0
// 			&& (args[i][0] != '0')
// 			&& (args[i][0] =! '-'
// 			|| args[i][0] =! '+'))
// 			|| (ft_atoi(args[i]) == 0
// 			&& (args[i][0] == '-'
// 			|| args[i][0] == '+')
// 			&& args[i][1] != 0)
