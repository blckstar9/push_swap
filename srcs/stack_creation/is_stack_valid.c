/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_stack_valid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 17:42:23 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/19 16:15:19 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	valid_string(char *str)
{
	int	i;
	int	in_number;

	if (!str || ft_strlen(str) == 0)
		return (0);
	i = -1;
	in_number = 0;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != 32 && str[i] != 45 && str[i] != 43)
			return (ft_putstr_fd(RED"Error\nInvalid string!\n"RS, 2), 0);
		if (str[i] == '-' || str[i] == '+')
		{
			if (!str[i + 1] || !ft_isdigit(str[i + 1]))
				return (ft_putstr_fd(RED"Error\nInvalid string!\n"RS, 2), 0);
			if (in_number)
				return (ft_putstr_fd(RED"Error\nInvalid string!\n"RS, 2), 0);
			in_number = 1;
		}
		else if (ft_isdigit(str[i]))
			in_number = 1;
		else if (str[i] == ' ')
			in_number = 0;
	}
	return (1);
}

int	valid_arg(char *arg)
{
	int	i;

	if (!arg || ft_strlen(arg) == 0)
		return (0);
	i = 0;
	if (arg[i] == '-' || arg[i] == '+')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (ft_putstr_fd(RED"Error\nInvalid argument!\n"RS, 2), 0);
		i++;
	}
	if (i == 1 && (arg[0] == '-' || arg[0] == '+'))
		return (ft_putstr_fd(RED"Error\nInvalid argument!\n"RS, 2), 0);
	return (1);
}

int	is_valid_int(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		num = num * 10 + (str[i] - '0');
		if (sign == 1 && num > INT_MAX)
			return (ft_putstr_fd(RED"Error\nOut of integer range!\n"RS, 2), 0);
		if (sign == -1 && (-num < INT_MIN))
			return (ft_putstr_fd(RED"Error\nOut of integer range!\n"RS, 2), 0);
		i++;
	}
	return (1);
}

int	has_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;
	int		first_pass;

	if (!stack)
		return (0);
	current = stack;
	first_pass = 1;
	while (current != stack || first_pass)
	{
		first_pass = 0;
		check = current->next;
		while (check != stack)
		{
			if (current->nbr == check->nbr)
				return (ft_putstr_fd(RED"Error\nDuplicate found!\n"RS, 2), 1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}
