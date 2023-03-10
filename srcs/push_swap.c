/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 14:34:06 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/05 14:22:14 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		j;
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_data	data;

	i = 1;
	j = 0;
	stack_a = NULL;
	stack_b = NULL;
	if (ac <= 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (0);
	}
	while (i < ac)
	{
		if (!ft_check_args(av[i], av, j))
		{
			ft_putstr_fd("Error\n", 1);
			return (0);
		}
		i++;
		j++;
	}
	i = 1;
	while (i < ac)
	{
		stack_a = ft_add_stack(stack_a, ft_atoi(av[i]));
		i++;
	}
	fill_tab(&stack_a, &data);
	presort(&stack_a, &stack_b, &data);

	/*
	printf("PILE A : \n");
	while (stack_a)
	{
		printf("%d\n", stack_a->value);
		stack_a = stack_a->next;
	}
	printf("PILE B : \n");
	while (stack_b)
	{
		printf("%d\n", stack_b->value);
		stack_b = stack_b->next;
	}
	*/
}
