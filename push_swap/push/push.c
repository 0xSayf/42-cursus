/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 22:18:07 by sahamzao          #+#    #+#             */
/*   Updated: 2024/07/31 19:33:24 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_pa(int *a, int *b, int *size_a, int *size_b)
{
	int	i;

	i = *size_a;
	if (*size_b == 0 || !b)
		return ;
	while (i > 0)
	{
		a[i] = a[i - 1];
		i--;
	}
	a[0] = b[0];
	i = 0;
	while (i < ((*size_b) - 1))
	{
		b[i] = b[i + 1];
		i++;
	}
	(*size_a)++;
	(*size_b)--;
	if (*size_b == 0)
		b = 0;
	write(1, "pa\n", ft_strlen("pa\n"));
}

void	ft_pb(int *a, int *b, int *size_a, int *size_b)
{
	int	i;

	i = *size_b;
	if (*size_a == 0 || !a)
		return ;
	while (i > 0)
	{
		b[i] = b[i - 1];
		i--;
	}
	b[0] = a[0];
	i = 0;
	while (i < ((*size_a) - 1))
	{
		a[i] = a[i + 1];
		i++;
	}
	(*size_b)++;
	(*size_a)--;
	if (*size_a == 0)
		a = 0;
	write(1, "pb\n", ft_strlen("pb\n"));
}
