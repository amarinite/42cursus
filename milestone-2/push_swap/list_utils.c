/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:25:10 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/21 16:25:13 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->ranking = 0;
	new_node->position_from_top = 0;
	new_node->position_from_bottom = 0;
	new_node->cost = 0;
	new_node->is_above = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->target = NULL;
	return (new_node);
}

t_stack	*new_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->size = 0;
	return (stack);
}

void	append_node_to_stack(t_stack *stack, t_node *new_node)
{
	t_node	*curr;

	if (!new_node || !stack)
		return ;
	if (!stack->head)
	{
		stack->head = new_node;
		stack->size = 1;
		return ;
	}
	curr = stack->head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
	new_node->prev = curr;
	stack->size++;
}

t_node	*pop_from_stack(t_stack *stack)
{
	t_node	*node;

	if (!stack || !stack->head)
		return (NULL);
	node = stack->head;
	stack->head = node->next;
	if (stack->head)
		stack->head->prev = NULL;
	node->next = NULL;
	stack->size--;
	return (node);
}

t_node	*pop_last_from_stack(t_stack *stack)
{
	t_node	*last;

	if (!stack || !stack->head)
		return (NULL);
	if (!stack->head->next)
	{
		last = stack->head;
		stack->head = NULL;
		stack->size = 0;
		return (last);
	}
	last = stack->head;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	stack->size--;
	return (last);
}
