#include "push_swap.h"

// void	sort_three(t_stack **a)
// {
// 	t_stack	*max;

// 	max = find_max(a);
// 	if (max == *a)
// 		ra(a);
// 	else if ((*a)->next == max)
// 		rra(a);
// 	if ((*a)->nbr > (*a)->next->nbr)
// 		sa(a);
// }

// void	sort_four(t_stack **a, t_stack **b)
// {
// 	t_stack	*min;

// 	min = find_min(a);
// 	if (!min)
// 		return ;
// 	while (*a != min)
// 	{
// 		if ((*a)->next == min || (*a)->next->next == min)
// 			ra(a);
// 		else
// 			rra(a);
// 	}
// 	pb(a, b);
// 	sort_three(a);
// 	pa(a, b);
// }

void sort_three(t_stack **a)
{
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a);
    if ((*a)->next->nbr > (*a)->next->next->nbr)
        rra(a);
    if ((*a)->nbr > (*a)->next->nbr)
        sa(a);
}

void sort_four(t_stack **a, t_stack **b)
{
    t_stack *min = find_min(a);
    if (!min)
        return ;
    
    // Eğer minimum ilk eleman ise, hiçbir şey yapmamıza gerek yok
    while (*a != min)
    {
        if ((*a)->next == min || (*a)->next->next == min)
            ra(a);
        else
            rra(a);
    }

    pb(a, b);
    sort_three(a);  // 3 elemanlı yığın sıralama
    pa(a, b);
}