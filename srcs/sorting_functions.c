/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 18:17:02 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/18 17:01:06 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	my_insertion_sort(t_pair *pairs, int count)
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

int	my_partition(t_pair *pairs, int low, int high)
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

void	my_quicksort(t_pair *pairs, int low, int high)
{
	int	pivot_idx;

	if (low < high)
	{
		pivot_idx = my_partition(pairs, low, high);
		my_quicksort(pairs, low, pivot_idx - 1);
		my_quicksort(pairs, pivot_idx + 1, high);
	}
}
