/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:50:12 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/19 15:19:20 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int count;
	if (argc < 2)
		return (ft_putstr_fd(RED"Error\n"RS, 2), 1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		if (!str_to_stack(argv[1], &stack_a))
			return (1);
	}
	else if (argc > 2)
	{
		if (!args_to_stack(argc, argv, &stack_a))
			return (1);
	}
	// Index the stack
    index_stack(stack_a);
    
    // Print initial stack
    printf(YL"\n--- Initial Stack ---\n"RS);
    printf("Stack A: ");
    t_stack *current = stack_a;
    int first_pass = 1;
    while (current != stack_a || first_pass)
    {
        first_pass = 0;
        printf("[%ld:%ld] ", current->nbr, current->index);
        current = current->next;
    }
    printf("\n");
    
    // Check if already sorted
    printf("\nIs initially sorted: %s\n", is_sorted(stack_a) ? GR"Yes"RS : RED"No"RS);
    
    // Test sort based on stack size
    count = count_stack(stack_a);
    printf(YL"\n--- Testing Sort Functions ---\n"RS);
    
    if (count == 2)
    {
        printf("Testing sort_two...\n");
        sort_two(&stack_a);
    }
    else if (count == 3)
    {
        printf("Testing sort_three...\n");
        sort_three(&stack_a);
    }
    else if (count <= 5)
    {
        printf("Testing sort_small for %d elements...\n", count);
        sort_small(&stack_a, &stack_b, count);
    }
    else
    {
        printf("Stack size %d: Using general sorting (not implemented yet).\n", count);
        // We'll implement general sorting later
    }
    
    // Print sorted stack
    printf(YL"\n--- After Sorting ---\n"RS);
    printf("Stack A: ");
    current = stack_a;
    first_pass = 1;
    while (current != stack_a || first_pass)
    {
        first_pass = 0;
        printf("[%ld:%ld] ", current->nbr, current->index);
        current = current->next;
    }
    printf("\n");
    
    // Verify sorting
    printf("\nIs now sorted: %s\n", is_sorted(stack_a) ? GR"Yes"RS : RED"No"RS);
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
