/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:50:12 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/11 23:54:35 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc < 2)
		return (ft_putstr_fd(RED"Error\n"RS, 2), 1);
	
	if (argc == 2)
	{
		// parse the string and pu the numbers in a list
		stack = str_to_stack(argv[1]);
		if (!stack)
			return (ft_putstr_fd(RED"Error\n"RS, 2), 1);
		while (stack)
		{
			ft_printf("%d\n", stack->nbr);
			stack = stack->next;
		}
		exit(EXIT_SUCCESS);
	}
	else if (argc > 2)
	{
		// parse the arguments and put the numbers in a list
		stack = args_to_stack(argc, argv);
		while (stack)
		{
			ft_printf("%d\n", stack->nbr);
			stack = stack->next;
		}
		exit(EXIT_SUCCESS);
	}
	// sort the list
	// print the operations
	// free the list
	free_stack(&stack);
	return (0);
}
