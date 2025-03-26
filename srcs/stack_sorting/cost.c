/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:58:21 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/24 18:13:15 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static int	calculate_position_cost(int position, int size)
{
	if (position > size / 2)
		return (-(size - position));
	return (position);
}

static void	initialize_cost(t_cost *cost, int position, int a_size, int index)
{
	cost->current_pos = position;
	cost->cost_a = calculate_position_cost(position, a_size);
	cost->index = index;
}

static void	calculate_target_cost(t_cost *cost, t_stack *stack_b)
{
	int	target_index;
	int	b_size;
	int	adjusted_pos;

	target_index = find_target_index(stack_b, cost->index);
	cost->target_pos = find_position(stack_b, target_index);
	b_size = count_stack(stack_b);
	adjusted_pos = cost->target_pos;
	if (cost->target_pos < 0)
		adjusted_pos = cost->target_pos + b_size;
	cost->cost_b = calculate_position_cost(adjusted_pos, b_size);
}

int	get_total_cost(t_cost cost)
{
	return (my_abs(cost.cost_a) + my_abs(cost.cost_b));
}

t_cost	*calculate_costs(t_stack *stack_a, t_stack *stack_b)
{
	t_cost	*costs;
	t_stack	*curr;
	int		a_size;
	int		i;
	int		first_pass;

	a_size = count_stack(stack_a);
	costs = malloc(a_size * sizeof(t_cost));
	if (!costs)
		return (NULL);
	curr = stack_a;
	i = 0;
	first_pass = 1;
	while (curr != stack_a || first_pass)
	{
		first_pass = 0;
		initialize_cost(&costs[i], i, a_size, curr->index);
		calculate_target_cost(&costs[i], stack_b);
		curr = curr->next;
		i++;
	}
	return (costs);
}
