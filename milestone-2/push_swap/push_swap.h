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

#include <limits.h>
# include "libft/libft.h"

typedef struct s_stack
{
	struct s_node	*head;
	int				size;
} t_stack;

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
t_stack	*new_stack(void);
void	append_node_to_stack(t_stack *stack, t_node *new_node);
int		initialize_stack(t_stack *stack, int argc, char **args);
int		handle_single_arg(t_stack *stack, char *arg);
int		check_overflow(char **args, int size);
int		check_duplicates(char **args, int size);
t_node	*pop_from_stack(t_stack *stack);
t_node	*pop_last_from_stack(t_stack *stack);
void	push(t_stack *stack, t_node *new_node);
void	pa(t_stack *stack_b, t_stack *stack_a);
void	pb(t_stack *stack_a, t_stack *stack_b);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ss(t_stack *stack_a, t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rr(t_stack *stack_a, t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_b);
void	rrr(t_stack *stack_a, t_stack *stack_b);
void	sort(t_stack *stack_a, t_stack *stack_b);
void	turkish(t_stack *stack_a, t_stack *stack_b);

#endif
