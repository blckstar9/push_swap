/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 16:36:46 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/21 22:42:25 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	count_stack(t_stack *stack)
{
	t_stack	*current;
	int		count;
	int		first_pass;

	if (!stack)
		return (0);
	count = 0;
	current = stack;
	first_pass = 1;
	while (current != stack || first_pass)
	{
		first_pass = 0;
		count++;
		current = current->next;
	}
	return (count);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;
	int		first_pass;

	if (!stack || stack->next == stack)
		return (1);
	current = stack;
	first_pass = 1;
	while (current->next != stack || first_pass)
	{
		first_pass = 0;
		if (current->index > current->next->index)
			return (0);
		current = current->next;
	}
	return (1);
}

int	find_position(t_stack *stack, int index)
{
	int		pos;
	int		size;
	t_stack	*current;
	int		first_pass;

	if (!stack)
		return (0);
	pos = 0;
	size = count_stack(stack);
	current = stack;
	first_pass = 1;
	while (current->index != index && (current != stack || first_pass))
	{
		first_pass = 0;
		pos++;
		current = current->next;
	}
	if (pos > size / 2)
		return (pos - size);
	return (pos);
}

void	move_to_top(t_stack **stack, int index, char stack_name)
{
	int	moves;

	moves = find_position(*stack, index);
	if (moves > 0)
	{
		while (moves--)
		{
			if (stack_name == 'a')
				rotate_a(stack);
			else
				rotate_b(stack);
		}
	}
	else
	{
		moves = -moves;
		while (moves--)
		{
			if (stack_name == 'a')
				reverse_rotate_a(stack);
			else
				reverse_rotate_b(stack);
		}
	}
}

int	my_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
