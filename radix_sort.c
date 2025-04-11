/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbulut <hbulut@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 18:10:59 by segunes           #+#    #+#             */
/*   Updated: 2025/04/11 18:12:37 by hbulut           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Yığın eleman sayısını hesaplayan fonksiyon
int	stack_size(t_stack *stack)
{
	int	size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
// void	assign_indexes(t_stack **stack)
// {
// 	t_stack	*current;
// 	int		index;

// 	current = *stack;
// 	index = 0;
// 	while (current)
// 	{
// 		current->index = index;
// 		index++;
// 		current = current->next;
// 	}
// }


void occur_all_number_index(t_stack **stack)
{
	t_stack *number;

	if (!stack || !(*stack))
		return;

	number = *stack;
	while (number)
	{
		number->index = -1;
		number = number->next;
	}
}

void assign_indexes(t_stack *stack)
{
	int     current_index = 0;
	t_stack *ptr;
	t_stack *min;
	
	// Tüm elemanlar indekslenene kadar
	while (1)
	{
		ptr = stack;
		min = NULL;

		// Henüz indekslenmemiş en küçük sayıyı bul
		while (ptr)
		{
			if (ptr->index == -1)
			{
				if (!min || ptr->nbr < min->nbr)
					min = ptr;
			}
			ptr = ptr->next;
		}

		// Eğer indekslenecek sayı kalmadıysa bitir
		if (!min)
			break;

		min->index = current_index;
		current_index++;
	}
}

// Maksimum bit uzunluğunu hesaplar
static int	get_max_bits(t_stack **stack_a)
{
	int	bit_size;
	int	a_size;

	bit_size = 0;
	a_size = stack_size(*stack_a);
	while (a_size > 1 && ++bit_size)
		a_size /= 2;
	return (bit_size);
}

static void	handle_small_stack(t_stack **stack_a, t_stack **stack_b, int *size)
{
	int	i;
	int	max_index;

	i = 0;
	max_index = 1;
	while (*size > 3 && i < 5 && stack_a != NULL)
	{
		if ((*stack_a)->index <= max_index)
			pb(stack_b, stack_a);
		else
			ra(stack_a);
		*size = stack_size(*stack_a);
		i++;
	}
	if (stack_a && stack_size(*stack_a) == 3)
		sort_three(stack_a);
	while (*stack_b)
		pa(stack_a, stack_b);
	if ((*stack_a)->index > (*stack_a)->next->index)
		sa(stack_a);
}

void	print_stack(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp)
	{
		printf("%d ", temp->nbr);
		temp = temp->next;
	}
}
// Radix sıralama fonksiyonu
void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	size;
	int	max_bits;
	int	j;

	i = 0;
	size = stack_size(*stack_a);                 // Yığının boyutunu al
	assign_indexes(*stack_a);                    
		// Yığın elemanlarına indeks atar
	handle_small_stack(stack_a, stack_b, &size);
		// Yığındaki 3 veya daha az eleman için hızlı sıralama
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < stack_size(*stack_a))
		{
			printf("burası");
			// Her bir bit için sıralama yapıyoruz
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b); // Eğer i. bit 0 ise
			else
				ra(stack_a); // Eğer i. bit 1 ise
		}
		// B yığındaki tüm elemanları stack_a'ya geri al
		while (*stack_b)
			pa(stack_a, stack_b);
		i++;
	}
	// Radix sıralamadan sonra son durumu yazdır
	printf("Stack A after radix_sort: ");
	print_stack(*stack_a);
}
