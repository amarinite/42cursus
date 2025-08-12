/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:53:59 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/23 11:54:03 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_already_sorted(t_stack *stack)
{
	t_node	*curr;
	int		val;

	curr = stack->head;
	val = 0;
	while (curr)
	{
		if (curr->ranking < val)
			return (0);
		val = curr->ranking;
		curr = curr->next;
	}
	return (1);
}

int	find_highest_ranking(t_stack *stack)
{
	int		highest;
	t_node	*curr;

	highest = 0;
	curr = stack->head;
	while (curr)
	{
		if (curr->ranking > highest)
			highest = curr->ranking;
		curr = curr->next;
	}
	return (highest);
}

void	sort_three(t_stack *stack)
{
	int		highest;
	t_node	*top;
	t_node	*middle;
	t_node	*bottom;

	highest = stack->size;
	top = stack->head;
	middle = stack->head->next;
	bottom = stack->head->next->next;
	highest = top->ranking;
	if (middle->ranking > highest)
		highest = middle->ranking;
	if (bottom->ranking > highest)
		highest = bottom->ranking;
	if (top->ranking == highest)
		ra(stack);
	else if (middle->ranking == highest)
		rra(stack);
	top = stack->head;
	middle = stack->head->next;
	if (top->ranking > middle->ranking)
		sa(stack);
}

void	sort(t_stack *stack_a, t_stack *stack_b)
{
	if (is_already_sorted(stack_a))
		return ;
	else if (stack_a->size == 2)
	{
		if (stack_a->head->content > stack_a->head->next->content)
			sa(stack_a);
		return ;
	}
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else
		turkish(stack_a, stack_b);
}
