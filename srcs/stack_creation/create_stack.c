/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 21:40:37 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/19 16:15:01 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
	t_stack	*first;

	if (!*stack)
	{
		*stack = new;
		new->next = new;
		new->prev = new;
		return ;
	}
	first = *stack;
	new->next = first;
	new->prev = first->prev;
	first->prev->next = new;
	first->prev = new;
}

int	str_to_stack(char *str, t_stack **stack)
{
	t_stack	*new;
	char	**split;
	int		i;

	if (!valid_string(str))
		return (0);
	split = ft_split(str, ' ');
	if (!split)
		return (0);
	i = -1;
	while (split[++i])
	{
		if (!is_valid_int(split[i]))
			return (free_stack(stack), free_split(split), 0);
		new = new_stack_node(ft_atoi(split[i]));
		if (!new)
			return (free_stack(stack), free_split(split), 0);
		stack_add_back(stack, new);
		free(split[i]);
	}
	free(split);
	if (has_duplicates(*stack))
		return (free_stack(stack), 0);
	return (1);
}

int	args_to_stack(int argc, char **argv, t_stack **stack)
{
	t_stack	*new;
	int		i;

	i = 0;
	while (++i < argc)
	{
		if (!valid_arg(argv[i]))
			return (free_stack(stack), 0);
		if (!is_valid_int(argv[i]))
			return (free_stack(stack), 0);
		new = new_stack_node(ft_atoi(argv[i]));
		if (!new)
			return (free_stack(stack), 0);
		stack_add_back(stack, new);
	}
	if (has_duplicates(*stack))
		return (free_stack(stack), 0);
	return (1);
}
