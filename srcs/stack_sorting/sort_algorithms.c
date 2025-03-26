/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algorithms.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:04:03 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/26 16:19:52 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;

	if (!*stack_a || size < 4)
		return ;
	i = 0;
	while (i < size - 3)
	{
		move_to_top(stack_a, i, 'a');
		push_b(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a);
	while (*stack_b)
		push_a(stack_a, stack_b);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!*stack_a || is_sorted(*stack_a))
		return ;
	size = count_stack(*stack_a);
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_small(stack_a, stack_b, size);
	else
		turk_sort(stack_a, stack_b);
}
