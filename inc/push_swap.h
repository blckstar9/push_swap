/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aybelaou <aybelaou@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:29:25 by aybelaou          #+#    #+#             */
/*   Updated: 2025/03/26 16:41:29 by aybelaou         ###   ########.fr       */
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

typedef struct s_pair
{
	long	value;
	t_stack	*node;
}	t_pair;

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	current_pos;
	int	target_pos;
	int	index;
}	t_cost;

// stack creation
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

// stack operations
void	swap_a(t_stack **stack_a);
void	swap_b(t_stack **stack_b);
void	swap_both(t_stack **stack_a, t_stack **stack_b);
void	push_a(t_stack **stack_a, t_stack **stack_b);
void	push_b(t_stack **stack_a, t_stack **stack_b);
void	rotate_a(t_stack **stack_a);
void	rotate_b(t_stack **stack_b);
void	rotate_both(t_stack **stack_a, t_stack **stack_b);
void	reverse_rotate_a(t_stack **stack_a);
void	reverse_rotate_b(t_stack **stack_b);
void	reverse_rotate_both(t_stack **stack_a, t_stack **stack_b);

// stack indexing
void	index_stack(t_stack *stack);

// stack sorting
int		is_sorted(t_stack *stack);
int		count_stack(t_stack *stack);
void	sort_two(t_stack **stack);
void	sort_three(t_stack **stack);
int		find_position(t_stack *stack, int index);
void	move_to_top(t_stack **stack, int index, char stack_name);
void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);

// turk sort algorithm
int		find_target_index(t_stack *stack_b, int index);
t_cost	*calculate_costs(t_stack *stack_a, t_stack *stack_b);
int		get_total_cost(t_cost cost);
int		my_abs(int a);
int		find_max_index(t_stack *stack);
int		find_cheapest_move(t_cost *costs, int size);
void	execute_rotations(t_stack **stack_a, t_stack **stack_b,
			int cost_a, int cost_b);
void	position_stack_for_insertion(t_stack **stack_a, int b_index);
void	turk_sort(t_stack **stack_a, t_stack **stack_b);

// sorting algorithms caller
void	sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif