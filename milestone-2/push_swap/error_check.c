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

int	handle_single_arg(t_stack *stack, char *arg)
{
	char	**splitted_args;
	int		i;
	int		result;

	splitted_args = ft_split(arg, ' ');
	if (!splitted_args)
		return (0);
	i = 0;
	while (splitted_args[i])
		i++;
	if (i == 1)
		return (free(splitted_args[i - 1]), free(splitted_args), 0);
	result = initialize_stack(stack, i, splitted_args);
	while (i > 0)
	{
		free(splitted_args[i - 1]);
		i--;
	}
	free(splitted_args);
	if (!result)
		ft_putstr_fd("Error\n", 1);
	return (result);
}
