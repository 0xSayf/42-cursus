/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 01:10:44 by sahamzao          #+#    #+#             */
/*   Updated: 2024/07/25 23:52:53 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rra(int *a, int size)
{
	int	reverse;
	int	i;

	i = 1;
	if (!a || size == 1 || size == 0)
		return ;
	reverse = a[size - 1];
	while (size - 1)
	{
		a[size - 1] = a[size - 2];
		size--;
	}
	a[0] = reverse;
	write(1, "rra\n", ft_strlen("rra\n"));
}

void	ft_rrb(int *b, int size)
{
	long	reverse;
	int		i;

	i = 1;
	if (!b || size == 1 || size == 0)
		return ;
	reverse = b[size - 1];
	while (size - 1)
	{
		b[size - 1] = b[size - 2];
		size--;
	}
	b[0] = reverse;
	write(1, "rrb\n", ft_strlen("rrb\n"));
}

void	ft_rrr(int *a, int *b, int size_a, int size_b)
{
	ft_rra(a, size_a);
	ft_rrb(b, size_b);
}
