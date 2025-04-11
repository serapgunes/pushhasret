/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 11:13:20 by segunes           #+#    #+#             */
/*   Updated: 2025/04/11 16:45:28 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	int				index;
	struct s_stack	*next;
}					t_stack;

int					init_stack_a(char **argv, t_stack **stack_a);
void				clean_up(t_stack *a, t_stack *b);
void				ft_check(char **nbr);

int					transfer_node(t_stack **dest_stack, t_stack **src_stack);
void				pb(t_stack **stack_a, t_stack **stack_b);
void				pa(t_stack **stack_a, t_stack **stack_b);

void				rrr(t_stack **stack_a, t_stack **stack_b);
void				rrb(t_stack **stack_b);
void				rra(t_stack **stack_a);

void				rr(t_stack **stack_a, t_stack **stack_b);
void				rb(t_stack **stack_b);
void				ra(t_stack **stack_a);

void				ss(t_stack **stack_a, t_stack **stack_b);
void				sb(t_stack **stack_b);
void				sa(t_stack **stack_a);

void				free_stack(t_stack **stack);
void				clean_up(t_stack *a, t_stack *b);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
t_stack				*find_max(t_stack **stack);
t_stack				*find_min(t_stack **stack);
void				sort_three(t_stack **a);
void				sort_four(t_stack **a, t_stack **b);
void				sort_five(t_stack **a, t_stack **b);
void				radix_sort(t_stack **stack_a, t_stack **stack_b);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
int					stack_size(t_stack *lst);
int					sizepush(t_stack **lst);

char				**merge_arguments(int argc, char **argv);
int					is_sorted(t_stack *stack);
int					stack_size(t_stack *stack);
void				assign_indexes(t_stack *stack);


#endif