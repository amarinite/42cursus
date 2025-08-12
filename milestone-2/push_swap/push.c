/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:41:18 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/23 10:41:20 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node *new_node)
{
	if (!stack || !new_node)
		return ;
	new_node->next = stack->head;
	if (stack->head)
		stack->head->prev = new_node;
	stack->head = new_node;
	stack->size++;
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	t_node	*node;

	node = pop_from_stack(stack_b);
	if (node)
		push(stack_a, node);
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*node;

	node = pop_from_stack(stack_a);
	if (node)
		push(stack_b, node);
	ft_putstr_fd("pb\n", 1);
}
