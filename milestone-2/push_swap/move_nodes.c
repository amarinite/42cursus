/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_nodes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:39:02 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/07 18:39:06 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	comb_mv(t_stack *a, t_stack *b, t_node *cheapest, t_costs costs)
{
	int	comb_moves;
	int	is_above;

	comb_moves = ft_min(costs.a, costs.b);
	is_above = cheapest->is_above;
	comb_rot(a, b, comb_moves, is_above);
	if (costs.a > costs.b)
		rotate_stack(a, costs.a - comb_moves, is_above, 'a');
	else if (costs.b > costs.a)
		rotate_stack(b, costs.b - comb_moves, cheapest->target->is_above, 'b');
}

void	move_nodes(t_stack *stack_a, t_stack *stack_b)
{
	int		cost_a;
	int		cost_b;
	t_node	*cheapest;
	t_costs	costs;

	cheapest = find_cheapest(stack_a);
	ind_costs(cheapest, cheapest->target, &cost_a, &cost_b);
	if (!cheapest->is_above)
		cost_a++;
	if (!cheapest->target->is_above)
		cost_b++;
	costs.a = cost_a;
	costs.b = cost_b;
	if (cheapest->is_above == cheapest->target->is_above)
		comb_mv(stack_a, stack_b, cheapest, costs);
	else
	{
		rotate_stack(stack_a, cost_a, cheapest->is_above, 'a');
		rotate_stack(stack_b, cost_b, cheapest->target->is_above, 'b');
	}
	pb(stack_a, stack_b);
}

void	move_back_to_a(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*target;
	t_node	*smallest;

	while (stack_b->head)
	{
		target = find_target_in_a(stack_b->head, stack_a);
		rotate_to_top(stack_a, target);
		pa(stack_b, stack_a);
	}
	smallest = find_smallest_node(stack_a);
	rotate_to_top(stack_a, smallest);
}
