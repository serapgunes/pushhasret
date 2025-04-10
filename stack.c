/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 14:39:20 by segunes           #+#    #+#             */
/*   Updated: 2025/03/15 14:39:20 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static void append_node(t_stack **stack, int value)
// {
// 	t_stack	*new_node;
// 	t_stack	*last;

// 	new_node = (t_stack *)malloc(sizeof(t_stack));
// 	if (!new_node)
// 		return ;
// 	new_node->nbr = value;
// 	new_node->index = 0;
// 	new_node->next = NULL;
// 	if (!(*stack))
//     {
// 		*stack = new_node;
//         write(1, "Added to stack\n", 15);
//     }
// 	else
// 	{
// 		last = *stack;
// 		while (last->next)
// 			last = last->next;
// 		last->next = new_node;
// 	}
// 	return ;
// }

// int check_duplicate(t_stack **stack)
// {
//     t_stack *temp;
//     t_stack *compare;

//     temp = *stack;
//     while (temp)
//     {
//         compare = temp->next;
//         while (compare)
//         {
//             if (temp->nbr == compare->nbr)
//             {
//                 write(2, "Error\n", 6);
//                 free_stack(stack);
//                 return 1; // Hata durumunda 1 döndür
//             }
//             compare = compare->next;
//         }
//         temp = temp->next;
//     }
//     return 0; // Eğer tekrar yoksa 0 döndür
// }

// int is_sorted(t_stack *stack)
// {
//     t_stack *temp;

//     temp = stack;
//     while (temp->next)
//     {
//         if (temp->nbr > temp->next->nbr)
//             return 0; // Sıralı değilse 0 döndür
//         temp = temp->next;
//     }
//     return 1; // Sıralıysa 1 döndür
// }

// void print_stack_a(t_stack *a)
// {
//     t_stack *temp;

//     temp = a;
//     while (temp)
//     {
//         printf("%d\n", temp->nbr);
//         temp = temp->next;
//     }
// }

// int init_stack_a(char **argv, t_stack **stack_a)
// {
//     long n;
//     int i;

//     i = 0;
//     while (argv[i])
//     {
//         n = ft_atoi(argv[i]);
//         if (n > INT_MAX || n < INT_MIN)
//         {
//             write(2, "Error\n", 6);
//             if (stack_a)
//                 free_stack(stack_a);
//             return (1); // Hata durumunda 1 döndür
//         }
//         append_node(stack_a, (int)n);
//         if (check_duplicate(stack_a))
//         {
//             if (stack_a)
//                 free_stack(stack_a);
//             return (1); // Tekrar kontrolünde hata varsa 1 döndür
//         }
//         i++;
//     }
//     // print_stack_a(*stack_a);
//     // if (is_sorted(*stack_a) == 1)
//     // {
//     //     printf("Sorted\n");
//     //     return (1);
//     // }
//     // printf("Not sorted\n");
//     return (0);
// }
static void append_node(t_stack **stack, int value)
{
	t_stack	*new_node;
	t_stack	*last;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->nbr = value;
	new_node->index = 0;
	new_node->next = NULL;
	if (!(*stack))
    {
		*stack = new_node;
        write(1, "Added to stack\n", 15);
    }
	else
	{
		last = *stack;
		while (last->next)
			last = last->next;
		last->next = new_node;
	}
	return ;
}

int check_duplicate(t_stack **stack)
{
    t_stack *temp;
    t_stack *compare;

    temp = *stack;
    while (temp)
    {
        compare = temp->next;
        while (compare)
        {
            if (temp->nbr == compare->nbr)
            {
                write(2, "Error\n", 6);
                free_stack(stack);
                return 1; // Hata durumunda 1 döndür
            }
            compare = compare->next;
        }
        temp = temp->next;
    }
    return 0; // Eğer tekrar yoksa 0 döndür
}

int is_sorted(t_stack *stack)
{
    t_stack *temp;

    temp = stack;
    while (temp->next)
    {
        if (temp->nbr > temp->next->nbr)
            return 0; // Sıralı değilse 0 döndür
        temp = temp->next;
    }
    return 1; // Sıralıysa 1 döndür
}

void print_stack_a(t_stack *a)
{
    t_stack *temp;

    temp = a;
    while (temp)
    {
        printf("%d\n", temp->nbr);
        temp = temp->next;
    }
}

int init_stack_a(char **argv, t_stack **stack_a)
{
    long n;
    int i;

    i = 0;
    while (argv[i])
    {
        n = ft_atoi(argv[i]);
        if (n > INT_MAX || n < INT_MIN)
        {
            write(2, "Error\n", 6);
            if (stack_a)
                free_stack(stack_a);
            return (1); // Hata durumunda 1 döndür
        }
        append_node(stack_a, (int)n);
        if (check_duplicate(stack_a))
        {
            if (stack_a)
                free_stack(stack_a);
            return (1); // Tekrar kontrolünde hata varsa 1 döndür
        }
        i++;
    }
     print_stack_a(*stack_a);
    // if (is_sorted(*stack_a) == 1)
    // {
    //     printf("Sorted\n");
    //     return (1);
    // }
    // printf("Not sorted\n");
    return (0);
}