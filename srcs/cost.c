/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 16:57:29 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/05 14:21:05 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int smallest_majorant(t_stack **a, t_data *data, int value)
{
    int     maj;
    t_stack *tmp;
    
    maj = data->max;
    tmp = *a;
    while (tmp)
    {
        if (value < tmp->value && maj > tmp->value)
            maj = tmp->value;
        tmp = tmp->next;
    }

    return (maj);
}

int cost_put_top(int value, t_stack **b)
{
    int     cost;
    int     size;
    t_stack *tmp;

    cost = 0;
    tmp = *b;
    size = ft_size_stack(*b);
    while (tmp && tmp->value != value && cost++)
        tmp = tmp->next;
    if (cost <= size / 2)
        return (cost);
    return (size - cost);
}

void    calcul_cost(t_stack **a, t_stack **b, t_data *data, int **tab)
{
    t_stack *tmp;
    int     i;
    int     maj;
    int     size;
    int     cost;

    i = 0;
    size = ft_size_stack(*b);
    tmp = *b;
    while (i < size)
    {
       tab[i] = malloc(sizeof(int) * 2);
       tab[i][1] = tmp->value;
       maj = smallest_majorant(a, data, tab[i][1]);
       cost = cost_put_top(tab[i][1], b) + cost_put_top(maj, a);
       tab[i][0] = cost;
       i++;
       tmp = tmp->next;
    } 
}

void	push_min_cost(t_stack **b, t_stack **a, t_data *data, int **tab)
{
    int i;
    int min;
    int maj;
    int size;

    i = 0;
    min = 0;
    size = ft_size_stack(*b);
    while (i < size)
    {
        if (tab[i][0] < tab[min][0])
		min = i;
		i++;     
    }
    maj = smallest_majorant(a, data, tab[min][1]);
    push_top_a(a, b, tab[min][1], maj);
}