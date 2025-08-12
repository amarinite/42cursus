/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:28:25 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/07 18:28:33 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_rotation_direction(t_stack *stack)
{
	t_node	*curr;

	if (!stack || !stack->head)
		return ;
	curr = stack->head;
	while (curr)
	{
		if (curr->position_from_top <= curr->position_from_bottom)
			curr->is_above = 1;
		else
			curr->is_above = 0;
		curr = curr->next;
	}
}

void	rotate_stack(t_stack *stack, int count, int is_above, char c)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (c == 'a')
		{
			if (is_above)
				ra(stack);
			else
				rra(stack);
		}
		else if (c == 'b')
		{
			if (is_above)
				rb(stack);
			else
				rrb(stack);
		}
		i++;
	}
}

void	comb_rot(t_stack *stack_a, t_stack *stack_b, int count, int is_above)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (is_above)
			rr(stack_a, stack_b);
		else
			rrr(stack_a, stack_b);
		i++;
	}
}

void	rotate_to_top(t_stack *stack, t_node *target)
{
	set_positions(stack);
	while (stack->head != target)
	{
		if (target->position_from_top <= target->position_from_bottom)
			ra(stack);
		else
			rra(stack);
		set_positions(stack);
	}
}
