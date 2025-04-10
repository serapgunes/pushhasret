/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:40:49 by segunes           #+#    #+#             */
/*   Updated: 2025/03/16 13:22:29 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_stack **stack)
{
	t_stack	*rec;
	t_stack	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return (-1);
	rec = *stack;
	while (rec->next->next)
		rec = rec->next;
	last = rec->next;
	rec->next = NULL;
	last->next = *stack;
	*stack = last;
	return (0);
}

void	rra(t_stack **stack_a)
{
	if (reverse_rotate(stack_a) == 0)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	if (reverse_rotate(stack_b) == 0)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	int	control_a;
	int	control_b;

	control_a = reverse_rotate(stack_a);
	control_b = reverse_rotate(stack_b);
	if (control_a == 0 || control_b == 0)
		write(1, "rrr\n", 4);
}