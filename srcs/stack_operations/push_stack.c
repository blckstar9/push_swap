/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:00:03 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/19 16:14:33 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	remove_from_stack(t_stack **stack, t_stack **node)
{
	*node = *stack;
	if ((*node)->next == *node)
		*stack = NULL;
	else
	{
		*stack = (*node)->next;
		(*node)->prev->next = (*node)->next;
		(*node)->next->prev = (*node)->prev;
	}
}

static void	add_to_stack(t_stack **stack, t_stack *node)
{
	if (!*stack)
	{
		*stack = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		node->next = *stack;
		node->prev = (*stack)->prev;
		(*stack)->prev->next = node;
		(*stack)->prev = node;
		*stack = node;
	}
}

static void	push_stack(t_stack **from, t_stack **to)
{
	t_stack	*temp;

	if (!*from)
		return ;
	remove_from_stack(from, &temp);
	add_to_stack(to, temp);
}

void	push_a(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push_stack(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}
