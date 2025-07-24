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
	// Not implemented
	return (0);
}

int	find_highest_ranking(t_stack *stack)
{
	// Not implemented
	return (stack->size);
}

void	sort_three(t_stack *stack)
{
	int	highest;
	t_node	*top;
	t_node	*middle;

	if (is_already_sorted(stack))
		return ;
	highest = stack->size;
	top = stack->head;
	middle = stack->head->next;
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
	if (stack_a->size == 2)
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
