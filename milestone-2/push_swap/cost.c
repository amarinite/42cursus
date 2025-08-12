/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/07 18:19:50 by amarquez          #+#    #+#             */
/*   Updated: 2025/08/07 18:19:52 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ind_costs(t_node *node_a, t_node *target_b, int *cost_a, int *cost_b)
{
	if (node_a->is_above)
		*cost_a = node_a->position_from_top;
	else
		*cost_a = node_a->position_from_bottom;
	if (target_b->is_above)
		*cost_b = target_b->position_from_top;
	else
		*cost_b = target_b->position_from_bottom;
}

void	calculate_cost(t_stack *stack_a)
{
	t_node	*curr;
	int		cost_a;
	int		cost_b;

	curr = stack_a->head;
	while (curr)
	{
		ind_costs(curr, curr->target, &cost_a, &cost_b);
		if (!curr->is_above)
			cost_a++;
		if (!curr->target->is_above)
			cost_b++;
		if (curr->is_above == curr->target->is_above)
		{
			if (cost_a > cost_b)
				curr->cost = cost_a;
			else
				curr->cost = cost_b;
		}
		else
			curr->cost = cost_a + cost_b;
		curr = curr->next;
	}
}

t_node	*find_cheapest(t_stack *stack_a)
{
	t_node	*curr;
	t_node	*cheapest;

	if (!stack_a || !stack_a->head)
		return (NULL);
	curr = stack_a->head;
	cheapest = stack_a->head;
	while (curr)
	{
		if (curr->cost < cheapest->cost)
			cheapest = curr;
		curr = curr->next;
	}
	return (cheapest);
}
