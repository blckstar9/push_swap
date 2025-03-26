/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_search.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:01:53 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/24 18:13:11 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	find_smallest_index(t_stack *stack)
{
	t_stack	*curr;
	int		smallest;
	int		first_pass;

	if (!stack)
		return (0);
	smallest = stack->index;
	curr = stack->next;
	first_pass = 1;
	while (curr != stack || first_pass)
	{
		first_pass = 0;
		if (curr->index < smallest)
			smallest = curr->index;
		curr = curr->next;
	}
	return (smallest);
}

static int	find_closest_larger_index(t_stack *stack, int index)
{
	t_stack	*curr;
	int		closest_larger;
	int		first_pass;

	if (!stack)
		return (-1);
	closest_larger = -1;
	curr = stack;
	first_pass = 1;
	while (curr != stack || first_pass)
	{
		first_pass = 0;
		if (curr->index > index && (closest_larger == -1
				|| curr->index < closest_larger))
			closest_larger = curr->index;
		curr = curr->next;
	}
	return (closest_larger);
}

int	find_target_index(t_stack *stack_b, int index)
{
	int	closest_larger;

	if (!stack_b)
		return (0);
	closest_larger = find_closest_larger_index(stack_b, index);
	if (closest_larger != -1)
		return (closest_larger);
	return (find_smallest_index(stack_b));
}

int	find_max_index(t_stack *stack)
{
	t_stack	*current;
	int		max_index;
	int		first_pass;

	if (!stack)
		return (0);
	max_index = stack->index;
	current = stack->next;
	first_pass = 1;
	while (current != stack || first_pass)
	{
		first_pass = 0;
		if (current->index > max_index)
			max_index = current->index;
		current = current->next;
	}
	return (max_index);
}

int	find_cheapest_move(t_cost *costs, int size)
{
	int	min_cost;
	int	min_index;
	int	i;
	int	total;

	min_cost = INT_MAX;
	min_index = 0;
	i = 0;
	while (i < size)
	{
		total = get_total_cost(costs[i]);
		if (total < min_cost)
		{
			min_cost = total;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
