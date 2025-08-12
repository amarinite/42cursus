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

void	cleanup(t_stack *stack)
{
	t_node	*curr;
	t_node	*nxt;

	if (!stack)
		return ;
	curr = stack->head;
	while (curr)
	{
		nxt = curr->next;
		free(curr);
		curr = nxt;
	}
	free(stack);
}

void	clean_stacks(t_stack *a, t_stack *b)
{
	cleanup(a);
	cleanup(b);
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

int	main(int argc, char **args)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !args[1] || !args[1][0])
		return (0);
	a = new_stack();
	b = new_stack();
	if (!a || !b)
		return (clean_stacks(a, b), 1);
	if (argc == 2)
	{
		if (!handle_single_arg(a, args[1]))
			return (clean_stacks(a, b), 1);
	}
	else if (!initialize_stack(a, argc - 1, args + 1))
		return (clean_stacks(a, b), ft_putstr_fd("Error\n", 1), 1);
	sort(a, b);
	clean_stacks(a, b);
	return (0);
}
