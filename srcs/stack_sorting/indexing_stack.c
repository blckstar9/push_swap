/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:17:02 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/21 17:20:14 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

static void	my_insertion_sort(t_pair *pairs, int count)
{
	int		i;
	int		j;
	t_pair	key;

	i = 0;
	while (++i < count)
	{
		key = pairs[i];
		j = i;
		while (--j >= 0 && pairs[j].value > key.value)
			pairs[j + 1] = pairs[j];
		pairs[j + 1] = key;
	}
}

static int	my_partition(t_pair *pairs, int low, int high)
{
	t_pair	pivot;
	int		i;
	int		j;
	t_pair	temp;

	pivot = pairs[high];
	i = low - 1;
	j = low - 1;
	while (++j < high)
	{
		if (pairs[j].value <= pivot.value)
		{
			temp = pairs[++i];
			pairs[i] = pairs[j];
			pairs[j] = temp;
		}
	}
	temp = pairs[i + 1];
	pairs[i + 1] = pairs[high];
	pairs[high] = temp;
	return (i + 1);
}

static void	my_quicksort(t_pair *pairs, int low, int high)
{
	int	pivot_idx;

	if (low < high)
	{
		pivot_idx = my_partition(pairs, low, high);
		my_quicksort(pairs, low, pivot_idx - 1);
		my_quicksort(pairs, pivot_idx + 1, high);
	}
}

static void	fill_pairs(t_stack *stack, t_pair *pairs)
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
