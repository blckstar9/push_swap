/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:04:03 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/18 18:26:50 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

void	sort_two(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	if ((*stack)->index > (*stack)->next->index)
		rotate_a(stack);
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	if (!*stack || (*stack)->next == *stack || (*stack)->next->next == *stack)
		return ;
	a = (*stack)->index;
	b = (*stack)->next->index;
	c = (*stack)->next->next->index;
	if (a < c && c < b)
		return (swap_a(stack), rotate_a(stack));
	else if (b < a && a < c)
		return (swap_a(stack));
	else if (b < c && c < a)
		return (rotate_a(stack));
	else if (c < a && a < b)
		return (reverse_rotate_a(stack));
	else if (c < b && b < a)
		return (rotate_a(stack), swap_a(stack));
}
