/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 21:29:39 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/04 21:55:29 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push2(int i, int j, t_stack **a, t_stack **b)
{
    if (j <= ft_size_stack(*a) - j)
	{
		while (j-- > 0)
			rotate(a, 'a');
	}
	else
	{
		while (ft_size_stack(*a) - j++ > 0)
			rrotate(a, 'a');
	}
	if (i <= ft_size_stack(*b) - i)
	{
		while (i-- > 0)
			rotate(b, 'b');
	}
	else
	{
		while (ft_size_stack(*b) - i++ > 0)
			rrotate(b, 'b');
	}
	push(a, b, 'a');
}

void    push_top_a(t_stack **a, t_stack **b, int value, int maj)
{
    int		i;
	int		j;
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = (*a);
	tmp_b = (*b);
	i = 0;
	j = 0;
	while (tmp_b && tmp_b->value != value)
	{
		tmp_b = tmp_b->next;
		i++;
	}
	while (tmp_a && tmp_a->value != maj)
	{
		tmp_a = tmp_a->next;
		j++;
	}
	push2(i, j, a, b);
}