/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:50:12 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/18 18:30:59 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

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
	return (free_stack(&stack_a), free_stack(&stack_b), 0);
}
