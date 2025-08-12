/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 13:04:16 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/24 13:04:20 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_overflow(char **args, int size)
{
	int			i;
	long int	num;

	i = 0;
	while (i < size)
	{
		num = ft_atol(args[i]);
		if (num > INT_MAX || num < INT_MIN)
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(char **args, int size)
{
	int	i;
	int	j;
	int	num1;
	int	num2;

	i = 0;
	while (i < size)
	{
		num1 = ft_atoi(args[i]);
		j = i + 1;
		while (j < size)
		{
			num2 = ft_atoi(args[j]);
			if (num1 == num2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
