/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:25:00 by sahamzao          #+#    #+#             */
/*   Updated: 2024/08/10 16:09:18 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *str, int *swp)
{
	int	swap;

	swap = str[0];
	str[0] = swp[0];
	swp[0] = swap;
}

void	ft_copy(int *a, int *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		b[i] = a[i];
		i++;
	}
	ft_reverse(b, size);
}

int	the_great(int *a, int size)
{
	int	i;
	int	great;
	int	j;

	i = 0;
	if (!a)
		return (0);
	great = a[0];
	j = i;
	while (i < size)
	{
		if (great < a[i])
		{
			great = a[i];
			j = i;
		}
		i++;
	}
	return (j);
}

void	ft_reverse(int *str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (str[i] > str[j])
				ft_swap(&str[i], &str[j]);
			j++;
		}
		i++;
	}
}

int	the_small(int *a, int size)
{
	int	i;
	int	small;
	int	j;

	i = 0;
	if (!a)
		return (0);
	small = a[0];
	j = i;
	while (i < size)
	{
		if (small > a[i])
		{
			small = a[i];
			j = i;
		}
		i++;
	}
	return (j);
}
