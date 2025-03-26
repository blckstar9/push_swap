/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:46:11 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/26 16:20:47 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	execute_combined_rotations(t_stack **stack_a, t_stack **stack_b,
									int *cost_a, int *cost_b)
{
	while (*cost_a > 0 && *cost_b > 0)
	{
		rotate_both(stack_a, stack_b);
		(*cost_a)--;
		(*cost_b)--;
	}
	while (*cost_a < 0 && *cost_b < 0)
	{
		reverse_rotate_both(stack_a, stack_b);
		(*cost_a)++;
		(*cost_b)++;
	}
}

static void	execute_rotations_a(t_stack **stack_a, int *cost_a)
{
	while (*cost_a > 0)
	{
		rotate_a(stack_a);
		(*cost_a)--;
	}
	while (*cost_a < 0)
	{
		reverse_rotate_a(stack_a);
		(*cost_a)++;
	}
}

static void	execute_rotations_b(t_stack **stack_b, int *cost_b)
{
	while (*cost_b > 0)
	{
		rotate_b(stack_b);
		(*cost_b)--;
	}
	while (*cost_b < 0)
	{
		reverse_rotate_b(stack_b);
		(*cost_b)++;
	}
}

void	execute_rotations(t_stack **stack_a, t_stack **stack_b,
					int cost_a, int cost_b)
{
	execute_combined_rotations(stack_a, stack_b, &cost_a, &cost_b);
	execute_rotations_a(stack_a, &cost_a);
	execute_rotations_b(stack_b, &cost_b);
}

void	position_stack_for_insertion(t_stack **stack_a, int b_index)
{
	t_stack	*curr_a;
	int		found;
	int		first_pass;

	curr_a = *stack_a;
	found = 0;
	first_pass = 1;
	while ((curr_a != *stack_a || first_pass) && !found)
	{
		first_pass = 0;
		if (curr_a->index < b_index && curr_a->next->index > b_index)
			found = 1;
		else if (curr_a->index > curr_a->next->index
			&& (b_index > curr_a->index || b_index < curr_a->next->index))
			found = 1;
		else
			curr_a = curr_a->next;
	}
	while (*stack_a != curr_a->next)
		rotate_a(stack_a);
}
