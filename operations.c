/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 13:44:45 by segunes           #+#    #+#             */
/*   Updated: 2025/03/20 18:35:26 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    transfer_node(t_stack **dest_stack, t_stack **src_stack)
{
    t_stack    *element;
    
    if (!src_stack || !(*src_stack))
        return (-1);
    element = *src_stack;
    *src_stack = element->next;
    element->next = *dest_stack;
    *dest_stack = element;
    return (0);
}
void    pa(t_stack **stack_a, t_stack **stack_b)
{
    if (transfer_node(stack_a, stack_b) == 0)
        write(1, "pa\n", 3);
}

void    pb(t_stack **stack_a, t_stack **stack_b)
{
    if (transfer_node(stack_b, stack_a) == 0)
        write(1, "pb\n", 3);
}