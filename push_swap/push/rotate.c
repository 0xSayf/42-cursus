/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 21:02:06 by sahamzao          #+#    #+#             */
/*   Updated: 2024/07/31 19:33:55 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ra(int *a, int size)
{
	int	rotate;
	int	i;

	i = 0;
	if (size == 0 || !a)
		return ;
	rotate = a[0];
	while (i < size - 1)
	{
		a[i] = a[i + 1];
		i++;
	}
	a[i] = rotate;
	write(1, "ra\n", ft_strlen("ra\n"));
}

void	ft_rb(int *b, int size)
{
	int	rotate;
	int	i;

	i = 0;
	if (size == 0 || !b)
		return ;
	rotate = b[0];
	while (i < size - 1)
	{
		b[i] = b[i + 1];
		i++;
	}
	b[i] = rotate;
	write(1, "rb\n", ft_strlen("rb\n"));
}

void	ft_rr(int *a, int *b, int size_a, int size_b)
{
	if (size_a == 0 || size_b == 0)
		return ;
	ft_ra(a, size_a);
	ft_rb(b, size_b);
	write(1, "rr\n", ft_strlen("rr\n"));
}
