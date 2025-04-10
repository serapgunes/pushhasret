/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:24:25 by segunes           #+#    #+#             */
/*   Updated: 2025/04/04 19:45:31 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack **create_stack(void)
{
    t_stack **stack;

    stack = (t_stack **)malloc(sizeof(t_stack *) * 500);
    if (!stack)
    {
        write(2, "Error\n", 6);
        return (NULL);
    }
    return (stack);
}
void check_arguments(int argc, char **argv, char ***number)
{
    *number = merge_arguments(argc, argv);
    if (!*number)
    {
        write(2, "Error\n", 6);
        exit(1);
    }
    ft_check(*number);
}
int main(int argc, char **argv)
{
    t_stack **stack_a;
    t_stack **stack_b;
    char **number;


    if (argc < 2)
        return (-1);
    check_arguments(argc, argv, &number);   
    stack_a = create_stack();
    stack_b = create_stack();
    init_stack_a(number, stack_a);
    if (!stack_a)
    {
        // clean_up(stack_a, stack_b);
        write(2, "Error2\n", 6);
        return (-1);
    }
    sort_stack(stack_a, stack_b);
    // clean_up(stack_a, stack_b);
    return (0);
}