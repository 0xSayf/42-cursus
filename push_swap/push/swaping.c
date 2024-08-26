/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swaping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:40:42 by sahamzao          #+#    #+#             */
/*   Updated: 2024/08/06 19:57:23 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(int *a, int size)
{
	int	swap;

	if (size == 0 || size == 1 || !a)
		return ;
	swap = a[0];
	a[0] = a[1];
	a[1] = swap;
	write(1, "sa\n", ft_strlen("sa\n"));
}

void	ft_sb(int *b, int size)
{
	long	swap;

	if (size == 0 || size == 1 || !b)
		return ;
	swap = b[0];
	b[0] = b[1];
	b[1] = swap;
	write(1, "sb\n", ft_strlen("sb\n"));
}

void	ft_ss(int *b, int *a, int size_a, int size_b)
{
	if (size_a == 0 || size_b == 1)
		return ;
	ft_sa(a, size_a);
	ft_sb(b, size_b);
	write(1, "ss\n", ft_strlen("ss\n"));
}
