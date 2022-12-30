/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymehlil <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:28:56 by ymehlil           #+#    #+#             */
/*   Updated: 2022/12/28 15:52:35 by ymehlil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_check_args(char *str, char **av, int j)
{
	int			i;
	long		nbr;

	i = 0;
	nbr = ft_atoi_long(str);
	if (nbr < 0 || str[0] == '+')
		i++;
	while (str[i])
	{	
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	if (nbr < -2147483648 || nbr > 2147483647 || i == 0)
		return (0);
	i = 1;
	while (av[i] && i <= j)
	{
		if (ft_atoi(av[i]) == nbr)
			return (0);
		i++;
	}
	return (1);
}
