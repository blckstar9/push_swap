/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:50:12 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/14 17:23:30 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void print_stack(t_stack *stack)
{
	t_stack *current;
	
	if (!stack)
	{
		write(1, "Empty stack\n", 12);
		return;
	}
	write(1, "Stack forward: ", 15);
	current = stack;
	do {
		ft_putnbr_fd(current->nbr, 1);
		write(1, " ", 1);
		current = current->next;
	} while (current != stack);
	write(1, "\n", 1);
	write(1, "Stack backward: ", 16);
	current = stack->prev;
	do {
		ft_putnbr_fd(current->nbr, 1);
		write(1, " ", 1);
		current = current->prev;
	} while (current != stack->prev);
	write(1, "\n", 1);
}

// Verify circular structure
int verify_stack(t_stack *stack)
{
	t_stack *current;
	int count = 0;
	
	if (!stack)
		return 1; // Empty stack is valid 
	current = stack;
	do {
		// Check next->prev pointer
		if (current->next->prev != current)
		{
			ft_printf("Error: broken link at node %d\n", count);
			return 0;
		}
		current = current->next;
		count++;
	} while (current != stack && count < 1000); // Safety limit
	if (count >= 1000)
	{
		ft_printf("Error: possible infinite loop in stack\n");
		return 0;
	}
	return 1; // Stack is valid
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	if (argc < 2)
		return (ft_putstr_fd(RED"Error\n"RS, 2), 1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		if (!str_to_stack(argv[1], &stack_a))
			return (1);
		print_stack(stack_a);
		verify_stack(stack_a);
	}
	else if (argc > 2)
	{
		if (!args_to_stack(argc, argv, &stack_a))
			return (1);
		print_stack(stack_a);
		verify_stack(stack_a);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
