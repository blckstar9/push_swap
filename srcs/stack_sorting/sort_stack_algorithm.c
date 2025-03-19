/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_algorithm.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 17:04:03 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/19 16:16:50 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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

/*
** Finds the position of the element with the given index
** Returns the number of moves needed (positive for ra, negative for rra)
*/
int find_position(t_stack *stack, int index)
{
    int pos;
    int size;
    t_stack *current;
    int first_pass;
    
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
        return (pos - size); // Negative for rra
    return (pos); // Positive for ra
}

/*
** Moves the element with the given index to the top of the stack
*/
void move_to_top(t_stack **stack, int index)
{
    int moves;
    
    moves = find_position(*stack, index);
    if (moves > 0)
    {
        while (moves--)
            rotate_a(stack);
    }
    else
    {
        moves = -moves;
        while (moves--)
            reverse_rotate_a(stack);
    }
}

/*
** Sort stack with 4-5 elements
*/
void sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
    int i;
    
    if (!*stack_a || size < 4)
        return ;
    i = 0;
    while (i < size - 3)
    {
        move_to_top(stack_a, i);
        push_b(stack_a, stack_b);
        i++;
    }
    sort_three(stack_a);
    while (*stack_b)
        push_a(stack_a, stack_b);
}