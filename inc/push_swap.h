/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:29:25 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/14 17:24:31 by aybelaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "../libft/inc/libft_inc/libft.h"
# include "../libft/inc/gnl_inc/get_next_line.h"
# include "../libft/inc/printf_inc/ft_printf.h"

# define RED "\033[31m"
# define RS "\033[0m"
# define CY "\033[36m"
# define YL "\033[33m"
# define GR "\033[32m"
# define MG "\033[35m"

typedef struct s_stack
{
	long			nbr;
	long			index;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*new_stack_node(long nbr);
void	stack_add_back(t_stack **stack, t_stack *new);
int		str_to_stack(char *str, t_stack **stack);
int		args_to_stack(int argc, char **argv, t_stack **stack);
int		valid_arg(char *arg);
int		valid_string(char *str);
int		is_valid_int(char *str);
int		has_duplicates(t_stack *stack);
void	free_stack(t_stack **stack);
void	free_split(char **split);
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);

#endif