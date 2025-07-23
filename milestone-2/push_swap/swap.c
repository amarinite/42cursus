/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:52:32 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/23 10:52:37 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_node **stack)
{
	t_node	*first;
	t_node	*second;

	if(!stack || !*stack || !(*stack)->next)
		return ;
	first = pop(stack);
	second = pop(stack);
	second->next = first;
	first->prev = second;
	first->next = *stack;
	if (*stack)
		(*stack)->prev = first;
	second->prev = NULL;
	*stack = second;
}

void	sa(t_node **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_node **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_node **stack_a, t_node **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
