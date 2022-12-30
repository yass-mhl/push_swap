/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:37:38 by ymehlil           #+#    #+#             */
/*   Updated: 2022/12/29 14:04:56 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	int		t;

	tmp = (*stack);
	t = tmp->value;
	if (*stack && (*stack)->next)
	{
		while (tmp->next)
		{
			tmp->value = (tmp->next)->value;
			tmp = tmp->next;
		}
		tmp->value = t;
		if (c)
		{
			write(1, "r", 1);
			write(1, &c, 1);
			write(1, "\n", 1);
		}
	}
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a, 0);
	rotate(stack_b, 0);
	ft_putstr_fd("rr\n", 1);
}
