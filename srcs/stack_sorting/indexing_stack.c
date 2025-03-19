/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:43:27 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/19 16:16:41 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	count_stack(t_stack *stack)
{
	t_stack	*current;
	int		count;
	int		first_pass;

	if (!stack)
		return (0);
	count = 0;
	current = stack;
	first_pass = 1;
	while (current != stack || first_pass)
	{
		first_pass = 0;
		count++;
		current = current->next;
	}
	return (count);
}

void	fill_pairs(t_stack *stack, t_pair *pairs)
{
	t_stack	*current;
	int		first_pass;
	int		i;

	if (!stack || !pairs)
		return ;
	current = stack;
	first_pass = 1;
	i = 0;
	while (current != stack || first_pass)
	{
		first_pass = 0;
		pairs[i].value = current->nbr;
		pairs[i].node = current;
		i++;
		current = current->next;
	}
}

void	index_stack(t_stack *stack)
{
	t_pair	*pairs;
	int		count;
	int		i;

	if (!stack)
		return ;
	count = count_stack(stack);
	pairs = malloc(count * sizeof(t_pair));
	if (!pairs)
		return ;
	fill_pairs(stack, pairs);
	if (count <= 20)
		my_insertion_sort(pairs, count);
	else
		my_quicksort(pairs, 0, count - 1);
	i = -1;
	while (++i < count)
		pairs[i].node->index = i;
	free(pairs);
}
