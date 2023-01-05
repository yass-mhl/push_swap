/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:27 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/04 22:04:59 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct stack {
	int				value;
	struct stack	*next;
}	t_stack;

typedef struct data {
	int	*tab;
	int	median;
	int	min;
	int	max;
	int	size;
}	t_data;

int			main(int ac, char **av);
int			ft_check_args(char *str, char **av, int j);
int			lst_len(t_stack lst);
int			ft_check_doubles(t_stack **stack);
int			ft_size_stack(t_stack *lst);
int			smallest_majorant(t_stack **a, t_data *data, int value);
long int	ft_atoi_long(const char *str);
int			cost_put_top(int value, t_stack **b);
void		parsing(int ac, char **av, t_stack *stack_a);
void		sa(t_stack **stack_a);
void		sb(t_stack **stack_b);
void		ss(t_stack **stack_a, t_stack **stack_b);
void		push(t_stack **stack_a, t_stack **stack_b, char c);
void		rotate(t_stack **stack, char c);
void		rr(t_stack **stack_a, t_stack **stack_b);
void		rrotate(t_stack **stack_a, char c);
void		rrr(t_stack **stack_a, t_stack **stack_b);
void		fill_tab(t_stack **stack, t_data *data);
void		ft_sort_int_tab(int *tab, int size);
void		presort(t_stack **stack_a, t_stack **stack_b, t_data *data);
void		stack_destroy(t_stack **stack);
void		free_list(t_stack *debut_a);
void		calcul_cost(t_stack **b, t_stack **a, t_data *data, int **tab);
void		push_top_a(t_stack **a, t_stack **b, int value, int maj);
void		push2(int i, int j, t_stack **a, t_stack **b);
void		sort(t_stack **stack_b, t_stack **stack_a, t_data *data);
void		push_min_cost(t_stack **b, t_stack **a, t_data *data, int **tab);
char		*create_array_ptr(t_stack *stack, int len);

t_stack		*ft_add_stack(t_stack *cell, int content);
#endif
