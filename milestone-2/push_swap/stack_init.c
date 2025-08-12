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

static t_node	*get_max_unranked_node(t_stack *stack)
{
	t_node	*curr;
	t_node	*max_node;
	int		max_val;

	curr = stack->head;
	max_node = NULL;
	max_val = INT_MIN;
	while (curr != NULL)
	{
		if (curr->content == INT_MIN && curr->ranking == 0)
			curr->ranking = 1;
		if (curr->content > max_val && curr->ranking == 0)
		{
			max_val = curr->content;
			max_node = curr;
		}
		curr = curr->next;
	}
	return (max_node);
}

static void	set_ranking(t_stack *stack)
{
	int		remaining_ranks;
	t_node	*node_to_rank;

	remaining_ranks = stack->size;
	while (remaining_ranks > 0)
	{
		node_to_rank = get_max_unranked_node(stack);
		if (node_to_rank)
			node_to_rank->ranking = remaining_ranks;
		remaining_ranks--;
	}
}

static int	is_valid_number(char *str)
{
	int	i;

	if (!str || str[0] == '\0')
		return (0);
	i = 0;
	if ((str[0] == '+' || str[0] == '-') && str[1] != '\0')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	validate_args(char **args, int argc)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!is_valid_number(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	initialize_stack(t_stack *stack, int argc, char **args)
{
	int		i;
	t_node	*node;

	if (!stack || !validate_args(args, argc))
		return (0);
	if (!check_overflow(args, argc) || !check_duplicates(args, argc))
		return (0);
	i = 0;
	while (i < argc)
	{
		node = new_node(ft_atoi(args[i]));
		if (!node)
			return (0);
		append_node_to_stack(stack, node);
		i++;
	}
	set_ranking(stack);
	return (1);
}
