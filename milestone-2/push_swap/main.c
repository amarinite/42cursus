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

void	printlist(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->head)
	{
		printf("List is empty.\n");
		return;
	}
	curr = stack->head;
	while (curr != NULL)
	{
		printf("%i\n", curr->content);
		curr = curr->next;
	}
}

void	print_rankings(t_stack *stack)
{
   t_node	*curr;

   if (!stack || !stack->head)
   {
   	printf("Stack is empty.\n");
   	return;
   }

   printf("Rankings: ");
   curr = stack->head;
   while (curr)
   {
   	printf("%d", curr->ranking);
   	if (curr->next)
   		printf(" -> ");
   	curr = curr->next;
   }
   printf("\n");
}

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



int	main(int argc, char **args)
{
	t_stack	*a;
	t_stack	*b;

	if (argc < 2 || !args[1] || !args[1][0])
		return (0);
	a = new_stack();
	b = new_stack();
	if (!a || !b)
	{
		cleanup(a);
		cleanup(b);
		return (1);
	}
	if (argc == 2)
	{
		if (!handle_single_arg(a, args[1]))
		{
			cleanup(a);
			cleanup(b);
			return (1);
		}
	}
	else if (!initialize_stack(a, argc - 1, args + 1))
	{
		cleanup(a);
		cleanup(b);
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	printlist(a);
	print_rankings(a);
	sort(a, b);
	printlist(a);
	print_rankings(a);
	cleanup(a);
	cleanup(b);
	return (0);
}
