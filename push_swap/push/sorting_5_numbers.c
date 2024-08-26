/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_5_numbers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:49:16 by sahamzao          #+#    #+#             */
/*   Updated: 2024/07/31 21:13:34 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_5_numbers(int *a, int *b, int *size_a, int *size_b)
{
	int	i;

	if (*size_a == 4)
		go_4_numbers(a, b, size_a, size_b);
	i = the_small(a, *size_a);
	ft_help(a, *size_a, i);
	ft_pb(a, b, size_a, size_b);
	i = the_small(a, *size_a);
	ft_help(a, *size_a, i);
	ft_pb(a, b, size_a, size_b);
	go_3_numbers(a, size_a);
	if (b[0] > b[1])
	{
		ft_pa(a, b, size_a, size_b);
		ft_pa(a, b, size_a, size_b);
	}
	else if (b[0] < b[1])
	{
		ft_sb(b, *size_b);
		ft_pa(a, b, size_a, size_b);
		ft_pa(a, b, size_a, size_b);
	}
}

void	go_4_numbers(int *a, int *b, int *size_a, int *size_b)
{
	int	i;

	i = the_small(a, *size_a);
	ft_help(a, *size_a, i);
	ft_pb(a, b, size_a, size_b);
	go_3_numbers(a, size_a);
	ft_pa(a, b, size_a, size_b);
}

void	ft_help(int *a, int size, int i)
{
	if (i == 1)
		ft_sa(a, size);
	else if (i >= 2)
	{
		while (i < size)
		{
			ft_rra(a, size);
			i++;
		}
	}
}
