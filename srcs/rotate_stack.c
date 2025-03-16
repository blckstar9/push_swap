/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:14:06 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/16 17:41:55 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate_stack(t_stack **stack)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
}

void	rotate_a(t_stack **stack_a)
{
	rotate_stack(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_stack **stack_b)
{
	rotate_stack(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	ft_putstr_fd("rr\n", 1);
}
