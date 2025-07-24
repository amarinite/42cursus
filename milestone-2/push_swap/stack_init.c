/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 17:27:50 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/24 17:27:52 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function assign_rankings(stack, stack_size):
//     remaining_ranks = stack_size

//     while remaining_ranks > 0:
//         current_max_value = INT_MIN
//         node_to_rank = NULL

//         // Find the biggest unranked value
//         for each node in stack:
//             if node.value == INT_MIN and node.ranking == 0:
//                 node.ranking = 1  // Handle edge case

//

void	set_ranking(t_stack *stack)
{
	int		remaining_ranks;
	int		max_val;
	t_node	*node_to_rank;
	t_node	*curr;

	remaining_ranks = stack->size;
	curr = stack->head;
	while (remaining_ranks > 0)
	{
		curr = stack->head;
		max_val = INT_MIN;
		node_to_rank = NULL;
		while (curr != NULL)
		{
			if (curr->content == INT_MIN && curr->ranking == 0)
				curr->ranking = 1;
			if (curr->content > max_val && curr->ranking == 0)
			{
				max_val = curr->content;
				node_to_rank = curr;
			}
			curr = curr->next;
		}
		if (node_to_rank)
			node_to_rank->ranking = remaining_ranks;
		remaining_ranks--;
	}
}

int	initialize_stack(t_stack *stack, int argc, char **args)
{
	int		i;
	int		j;
	t_node	*node;

	if (!stack)
		return (0);
	i = 0;
	while (i < argc)
	{
		if (args[i][0] == '\0')
			return (0);
		j = 0;
		if ((args[i][0] == '+' || args[i][0] == '-') && args[i][1] != '\0')
			j++;
		while (args[i][j] != '\0')
		{
			if (!ft_isdigit(args[i][j]))
				return (0);
			j++;
		}
		if (!check_overflow(args, argc) || !check_duplicates(args, argc))
			return (0);
		node = new_node(ft_atoi(args[i]));
		if (!node)
			return (0);
		append_node_to_stack(stack, node);
		i++;
	}
	set_ranking(stack);
	return (1);
}
