/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:24:58 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/21 18:40:05 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	reverse_rotate_stack(t_stack **stack)
{
	if (!*stack || (*stack)->prev == *stack)
		return ;
	*stack = (*stack)->prev;
}

void	reverse_rotate_a(t_stack **stack_a)
{
	reverse_rotate_stack(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_stack **stack_b)
{
	reverse_rotate_stack(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
