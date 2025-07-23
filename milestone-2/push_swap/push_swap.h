/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 13:59:18 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/21 13:59:21 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int				content;
	int				ranking;
	int				is_cheapest;
	int				is_above;
	struct s_node	*prev;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

t_node	*new_node(int content);
void	append_node(t_node **head, t_node *new_node);
int		initialize_stack(t_node **head, int argc, char **args);
int		check_duplicates(char **args, int size);
t_node	*pop(t_node **head);
t_node	*pop_last(t_node **head);
void	push(t_node **head, t_node *new_node);
void	pa(t_node **stack_b, t_node **stack_a);
void	pb(t_node **stack_a, t_node **stack_b);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	ra(t_node **stack_a);
void	rb(t_node **stack_b);
void	rr(t_node **stack_a, t_node **stack_b);
void	rra(t_node **stack_a);
void	rrb(t_node **stack_b);
void	rrr(t_node **stack_a, t_node **stack_b);
void	sort(t_node **stack_a, t_node **stack_b, int argc);
void	turkish(t_node **stack_a, t_node **stack_b);

#endif
