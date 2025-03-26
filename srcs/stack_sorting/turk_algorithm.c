/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 16:18:59 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/26 16:38:32 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

/* Prepare stacks by pushing all but 3 elements from A to B */
static void	prepare_stacks(t_stack **stack_a, t_stack **stack_b)
{
	t_cost	*costs;
	int		cheapest;

	if (count_stack(*stack_a) > 3 && !is_sorted(*stack_a))
		push_b(stack_a, stack_b);
	while (count_stack(*stack_a) > 3)
	{
		costs = calculate_costs(*stack_a, *stack_b);
		if (!costs)
			return ;
		cheapest = find_cheapest_move(costs, count_stack(*stack_a));
		execute_rotations(stack_a, stack_b,
			costs[cheapest].cost_a, costs[cheapest].cost_b);
		push_b(stack_a, stack_b);
		free(costs);
	}
}

/* Push elements back from B to A in proper order */
static void	restore_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	b_index;

	while (*stack_b)
	{
		b_index = find_max_index(*stack_b);
		move_to_top(stack_b, b_index, 'b');
		position_stack_for_insertion(stack_a, b_index);
		push_a(stack_a, stack_b);
	}
	move_to_top(stack_a, 0, 'a');
}

/* Main sorting algorithm using Turk method */
void	turk_sort(t_stack **stack_a, t_stack **stack_b)
{
	prepare_stacks(stack_a, stack_b);
	sort_three(stack_a);
	restore_stack(stack_a, stack_b);
}
