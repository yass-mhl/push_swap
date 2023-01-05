/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:49:55 by ymehlil           #+#    #+#             */
/*   Updated: 2023/01/01 17:31:00 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

long int	ft_atoi_long(const char *str)
{
	int			i;
	int			neg;
	long int	n;

	i = 0;
	neg = 1;
	n = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - 48);
		i++;
	}
	return (n * neg);
}

t_stack	*ft_add_stack(t_stack *cell, int content)
{
	t_stack	*new;
	t_stack	*tmp;

	tmp = cell;
	new = malloc(sizeof(t_stack));
	new->value = content;
	new->next = NULL;
	if (!cell)
	{
		cell = new;
		return (cell);
	}
	while (cell->next)
		cell = cell->next;
	cell->next = new;
	return (tmp);
}

int	ft_size_stack(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (j < size)
	{	
		while (j < size)
		{
			if ((tab[j]) < (tab[i]))
			{
				tmp = tab[j];
				tab[j] = tab[i];
				tab[i] = tmp;
			}
			j++;
		}
		j = i + 1;
		i++;
	}
}

void	free_list(t_stack *debut_a)
{
	t_stack	*temp_debut_a;

	while (debut_a != NULL)
	{
		temp_debut_a = debut_a;
		debut_a = debut_a->next;
		free(temp_debut_a);
	}
}
