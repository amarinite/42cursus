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

void	push(t_node **head, t_node *new_node)
{
	if (!head || !new_node)
		return ;
	new_node->next = *head;
	if (*head)
		(*head)->prev = new_node;
	*head = new_node;
}

void	pa(t_node **stack_b, t_node **stack_a)
{
	push(stack_a, pop(stack_b));
	ft_putstr_fd("pa\n", 1);
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	push(stack_b, pop(stack_a));
	ft_putstr_fd("pb\n", 1);
}
