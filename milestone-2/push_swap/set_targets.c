/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_targets.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 15:33:00 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/07 15:33:02 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*find_biggest_node(t_stack *stack)
{
	t_node	*curr;
	t_node	*biggest;

	if (!stack || !stack->head)
		return (NULL);
	biggest = stack->head;
	curr = stack->head;
	while (curr)
	{
		if (curr->ranking > biggest->ranking)
			biggest = curr;
		curr = curr->next;
	}
	return (biggest);
}

t_node	*find_smallest_node(t_stack *stack)
{
	t_node	*curr;
	t_node	*smallest;

	if (!stack || !stack->head)
		return (NULL);
	smallest = stack->head;
	curr = stack->head;
	while (curr)
	{
		if (curr->ranking < smallest->ranking)
			smallest = curr;
		curr = curr->next;
	}
	return (smallest);
}

t_node	*find_target_in_b(t_node *node_a, t_stack *stack_b)
{
	t_node	*curr_b;
	t_node	*target;
	t_node	*biggest;

	biggest = find_biggest_node(stack_b);
	target = NULL;
	curr_b = stack_b->head;
	while (curr_b)
	{
		if (curr_b->ranking < node_a->ranking)
		{
			if (!target || curr_b->ranking > target->ranking)
				target = curr_b;
		}
		curr_b = curr_b->next;
	}
	if (!target)
		target = biggest;
	return (target);
}

t_node	*find_target_in_a(t_node *node_b, t_stack *stack_a)
{
	t_node	*curr_a;
	t_node	*target;
	t_node	*smallest;

	smallest = find_smallest_node(stack_a);
	target = NULL;
	curr_a = stack_a->head;
	while (curr_a)
	{
		if (curr_a->ranking > node_b->ranking)
		{
			if (!target || curr_a->ranking < target->ranking)
				target = curr_a;
		}
		curr_a = curr_a->next;
	}
	if (!target)
		target = smallest;
	return (target);
}

void	set_targets(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*curr_a;

	if (!stack_a || !stack_b || !stack_a->head || !stack_b->head)
		return ;
	curr_a = stack_a->head;
	while (curr_a)
	{
		curr_a->target = find_target_in_b(curr_a, stack_b);
		curr_a = curr_a->next;
	}
}
