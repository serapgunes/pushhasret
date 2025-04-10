#include "push_swap.h"

t_stack	*find_max(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*max;

	if (!stack || !*stack)
		return (NULL);
	max = *stack;
	tmp = max->next;
	while (tmp)
	{
		if (tmp->nbr > max->nbr)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

t_stack	*find_min(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*min;

	if (!stack || !*stack)
		return (NULL);
	min = *stack;
	tmp = min->next;
	while (tmp)
	{
		if (tmp->nbr < min->nbr)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}