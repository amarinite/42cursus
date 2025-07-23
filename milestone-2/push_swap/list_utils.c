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

#include "libft/libft.h"
#include "push_swap.h"

t_node	*new_node(int content)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	if (new_node == NULL)
		return (NULL);
	new_node->content = content;
	new_node->is_above = 0;
	new_node->is_cheapest = 0;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->target = NULL;
	return (new_node);
}

void	append_node(t_node **head, t_node *new_node)
{
	t_node	*curr;

	if (!new_node)
		return ;
	if (!*head)
	{
		*head = new_node;
		return ;
	}
	curr = *head;
	while (curr->next != NULL)
		curr = curr->next;
	curr->next = new_node;
	new_node->prev = curr;
}

t_node	*pop(t_node **head)
{
	t_node	*node;

	if (!head || !*head)
		return (NULL);
	node = *head;
	*head = node->next;
	if (*head)
		(*head)->prev = NULL;
	node->next = NULL;
	return (node);
}

t_node	*pop_last(t_node **head)
{
	t_node	*last;

	if (!head || !*head)
		return (NULL);
	if (!(*head)->next)
	{
		last = *head;
		*head = NULL;
		return (last);
	}
	last = *head;
	while (last->next)
		last = last->next;
	last->prev->next = NULL;
	last->prev = NULL;
	return (last);
}

int	initialize_stack(t_node **head, int argc, char **args)
{
	int		i;
	int		j;
	t_node	*node;

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
		if (!check_duplicates(args, argc))
			return (0);
		node = new_node(ft_atoi(args[i]));
		append_node(head, node);
		i++;
	}
	return (1);
}
