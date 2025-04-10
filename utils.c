/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:39:26 by segunes           #+#    #+#             */
/*   Updated: 2025/04/05 01:20:48 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	stack_size(t_stack *lst)
// {
// 	int	size;

// 	size = 0;
// 	while (lst != NULL)
// 	{
// 		size++;
// 		lst = lst->next;
// 	}
// 	return (size);
// }
int	sizepush(t_stack **lst)
{
	t_stack	*stl;
	size_t	i;

	stl = *lst;
	i = 0;
	while (stl != NULL)
	{
		stl = stl->next;
		i++;
	}
	return (i);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = stack_size(*stack_a);
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
		
}