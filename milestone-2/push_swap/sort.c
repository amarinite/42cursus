/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 11:53:59 by amarquez          #+#    #+#             */
/*   Updated: 2025/07/23 11:54:03 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_ranking(t_node **head)
{

}

void	sort_three(t_node **head)
{


}

void	sort(t_node **stack_a, t_node **stack_b, int argc)
{
	if (argc == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		return ;
	}
	else if (argc == 3)
		sort_three(stack_a);
	else
		turkish(stack_a, stack_b);
}
