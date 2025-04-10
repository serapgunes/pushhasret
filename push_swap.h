/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: segunes <segunes@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:13:20 by segunes           #+#    #+#             */
/*   Updated: 2025/04/05 01:20:27 by segunes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack // struct s_stack: Bu, yapıyı tanımlar ve s_stack yapısının bir tür adı olmasını sağlar.
{
    int nbr; 
    int index;             // Stack'teki elemanın verisini tutan bir integer
    struct s_stack *next;    // Bir sonraki stack elemanının adresini tutan pointer
}   t_stack;//t_stack: typedef sayesinde,struct s_stack türüne verdiğiniz başka bir takma ad. Artık t_stack

int init_stack_a(char **argv, t_stack **stack_a);
void clean_up(t_stack *a, t_stack *b);
void ft_check(char **nbr);

int    transfer_node(t_stack **dest_stack, t_stack **src_stack);
void    pb(t_stack **stack_a, t_stack **stack_b);
void    pa(t_stack **stack_a, t_stack **stack_b);

void	rrr(t_stack **stack_a, t_stack **stack_b);
void	rrb(t_stack **stack_b);
void	rra(t_stack **stack_a);

void	rr(t_stack **stack_a, t_stack **stack_b);
void	rb(t_stack **stack_b);
void	ra(t_stack **stack_a);

void	ss(t_stack **stack_a, t_stack **stack_b);
void	sb(t_stack **stack_b);
void	sa(t_stack **stack_a);

void free_stack(t_stack **stack);
void clean_up(t_stack *a, t_stack *b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
t_stack	*find_max(t_stack **stack);
t_stack	*find_min(t_stack **stack);
void	sort_three(t_stack **a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	sort_stack(t_stack **stack_a, t_stack **stack_b);
int	stack_size(t_stack *lst);
int	sizepush(t_stack **lst);

char **merge_arguments(int argc, char **argv);
int is_sorted(t_stack *stack);
int stack_size(t_stack *stack);

#endif