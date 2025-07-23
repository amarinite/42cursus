/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 15:50:38 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/21 15:50:41 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	printlist(t_node *a)
{
	t_node	*curr = a;

	if (!a)
	{
		printf("List is empty.\n");
		return;
	}
	while (curr != NULL)
	{
		printf("%i\n", curr->content);
		curr = curr->next;
	}
}

void	cleanup(t_node **head)
{
	t_node	*curr;
	t_node	*nxt;

	if (!head)
		return ;
	curr = *head;
	while (curr)
	{
		nxt = curr->next;
		free(curr);
		curr = nxt;
	}
	*head = NULL;
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

int	handle_single_arg(t_node **a, char *arg)
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
		return (free(splitted_args[i - 1]), free(splitted_args),
			ft_putstr_fd("Program needs more than one number\n", 1), 0);
	result = initialize_stack(a, i, splitted_args);
	while (i > 0)
	{
		free(splitted_args[i - 1]);
		i--;
	}
	free(splitted_args);
	if (!result)
		ft_putstr_fd("Program only takes non-duplicate numbers\n", 1);
	return (result);
}

int	main(int argc, char **args)
{
	t_node	*a;
	t_node	*b;

	if (argc < 2 || !args[1][0])
		return (ft_putstr_fd("Invalid args\n", 1), 1);
	a = NULL;
	b = NULL;
	if (argc == 2)
	{
		if (!handle_single_arg(&a, args[1]))
		{
			cleanup(&a);
			return (1);
		}
	}
	else if (!initialize_stack(&a, argc - 1, args + 1))
		return (cleanup(&a), ft_putstr_fd("Program only takes non-duplicate numbers\n", 1), 1);
	//printlist(a);
	cleanup(&a);
	cleanup(&b);
	return (0);
}
