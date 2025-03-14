/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 15:59:24 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/14 17:01:57 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap_stack(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || (*stack)->next == *stack)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	second->prev = first->prev;
	first->prev = second;
	first->next->prev = first;
	second->prev->next = second;
	*stack = second;
}

void	swap_a(t_stack **stack_a)
{
	swap_stack(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_stack **stack_b)
{
	swap_stack(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	swap_both(t_stack **stack_a, t_stack **stack_b)
{
	swap_stack(stack_a);
	swap_stack(stack_b);
	ft_putstr_fd("ss\n", 1);
}
