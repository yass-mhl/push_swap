/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 17:46:08 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/05 01:23:03 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    fill_tab(t_stack **stack, t_data *data)
{
    t_stack *tmp;
    int     i;
    
    i = 0;
    tmp = (*stack);
    data->size = ft_size_stack(tmp);
    data->tab = (int *)malloc(sizeof(int) * data->size);
	while (tmp)
	{
		data->tab[i++] = tmp->value;
		tmp = tmp->next;
	}
    ft_sort_int_tab(data->tab, data->size);
    data->min = data->tab[0];
    data->max = data->tab[data->size - 1];
    data->median = data->tab[data->size / 2];
}

void    presort(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
    while (ft_size_stack(*stack_a) > 1)
    {
        if ((*stack_a)->value == data->max)
            rotate(stack_a, 'a');
        push(stack_b, stack_a, 'b');
        if ((*stack_b)->value < data->median)
            rotate(stack_b, 'b');
    }
   sort(stack_a, stack_b, data);
}

void    sort(t_stack **stack_a, t_stack **stack_b, t_data *data)
{
    int **tab;

    tab = malloc(sizeof(int *) * ft_size_stack(*stack_b));
    while (ft_size_stack(*stack_b))
    {
        calcul_cost(stack_a, stack_b, data, tab);
        push_min_cost(stack_b, stack_a, data, tab);
    }
    while ((*stack_a)->value != data->min)
	{
		rotate(stack_a, 'a');
	}
}