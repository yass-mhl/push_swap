/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 15:41:12 by ymehlil           #+#    #+#             */
/*   Updated: 2022/12/28 22:23:49 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rrotate(t_stack **stack_a, char c)
{
	t_stack	*tmp;
	t_stack	*before_last;

	tmp = (*stack_a);
	while (tmp->next)
	{
		before_last = tmp;
		tmp = tmp->next;
	}
	tmp->next = (*stack_a);
	(*stack_a) = tmp;
	before_last->next = NULL;
	if (c)
	{
		write(1, "rr", 2);
		write(1, &c, 1);
		write(1, "\n", 1);
	}
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	rrotate(stack_a, 0);
	rrotate(stack_b, 0);
	ft_putstr_fd("rrr\n", 1);
}
