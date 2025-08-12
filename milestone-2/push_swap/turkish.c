/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turkish.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:02:29 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/23 12:02:31 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_positions(t_stack *stack)
{
	t_node	*curr;
	int		pos_from_top;

	if (!stack || !stack->head)
		return ;
	pos_from_top = 0;
	curr = stack->head;
	while (curr)
	{
		curr->position_from_top = pos_from_top;
		curr->position_from_bottom = (stack->size - 1) - pos_from_top;
		pos_from_top++;
		curr = curr->next;
	}
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

void	turkish(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->size == 0)
	{
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
	}
	while (stack_a->size > 3)
	{
		set_positions(stack_a);
		set_positions(stack_b);
		set_targets(stack_a, stack_b);
		set_rotation_direction(stack_a);
		set_rotation_direction(stack_b);
		calculate_cost(stack_a);
		move_nodes(stack_a, stack_b);
	}
	sort_three(stack_a);
	move_back_to_a(stack_a, stack_b);
}
