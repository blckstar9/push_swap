/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:50:12 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/13 17:38:42 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int main(int argc, char **argv)
{
    t_stack *stack;
    t_stack *head;

    if (argc < 2)
        return (ft_putstr_fd(RED"Error\n"RS, 2), 1);
    if (argc == 2)
    {
        stack = str_to_stack(argv[1]);
        if (!stack)
            return (1);
        head = stack;
        while (stack)
        {
            ft_printf("%d\n", stack->nbr);
            stack = stack->next;
        }
        free_stack(&head);
    }
    else if (argc > 2)
    {
        stack = args_to_stack(argc, argv);
        if (!stack)
            return (1);
        head = stack;
        while (stack)
        {
            ft_printf("%d\n", stack->nbr);
            stack = stack->next;
        }
        free_stack(&head);
    }
    return (0);
}
