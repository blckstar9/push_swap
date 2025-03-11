/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:40:37 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/11 23:57:07 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void free_stack(t_stack **stack)
{
    t_stack *current;
    t_stack *next;

    if (!stack || !*stack)
        return;
    current = *stack;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *stack = NULL;
}

t_stack	*new_stack_node(long nbr)
{
	t_stack	*list;

	list = malloc(sizeof(t_stack));
	if (!list)
		return (NULL);
	list->nbr = nbr;
	list->index = 0;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

void	stack_add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next)
		last = last->next;
	last->next = new;
	new->prev = last;
}

int valid_string(char *str)
{
    int i;

    if (!str || ft_strlen(str) == 0)
        return (0);
    i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '+')
            return (ft_printf(RED"Error\nBad string given!\n"RS), 0);
        if ((str[i] == '-' || str[i] == '+') && 
            (!str[i+1] || !ft_isdigit(str[i+1])))
            return (ft_printf(RED"Error\nBad string given!\n"RS), 0);
        i++;
    }
    return (1);
}

t_stack	*str_to_stack(char *str)
{
	t_stack	*stack;
	t_stack	*new;
	char	**split;
	int		i;

	stack = NULL;
    if (!valid_string(str))
		return (NULL);
    split = ft_split(str, ' ');
	if (!split)
		return (NULL);
	i = -1;
	while (split[++i])
	{
		new = new_stack_node(ft_atoi(split[i]));
        if (!new)
        {
            free_stack(&stack);
            free(split[i]);
            while (split[++i])
                free(split[i]);
            free(split);
            return (NULL);
        }
		stack_add_back(&stack, new);
		free(split[i]);
	}
	free(split);
	return (stack);
}

t_stack	*args_to_stack(int argc, char **argv)
{
	t_stack	*stack;
	t_stack	*new;
	int		i;

	stack = NULL;
	i = 0;
	while (++i < argc)
	{
		new = new_stack_node(ft_atoi(argv[i]));
		if (!new)
			return (NULL);
		stack_add_back(&stack, new);
	}
	return (stack);
}
