/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_up_to_5_numbers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 22:54:27 by sahamzao          #+#    #+#             */
/*   Updated: 2024/08/11 21:57:16 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	go_up_to_5(int *a, int *b, int *size_a, int *size_b)
{
	int		*reverse;
	t_node	t_node;

	t_node.range[0] = ft_range(*size_a);
	t_node.f[0] = *size_a;
	reverse = malloc(sizeof(int) * (*size_a));
	ft_copy(a, reverse, *size_a);
	t_node.id_range[0] = 0;
	while (*size_a)
	{
		if (ft_find(a[0], reverse, t_node.f[0]) <= t_node.range[0])
		{
			ft_pb(a, b, size_a, size_b);
			if (ft_find(a[0], reverse, t_node.f[0]) > t_node.id_range[0])
				ft_rb(b, *size_b);
			(t_node.id_range[0])++;
			(t_node.range[0])++;
		}
		else
			ft_ra(a, *size_a);
	}
	ft_final_operation(a, b, size_a, size_b);
	free(reverse);
}

int	ft_range(int size)
{
	int	range;

	range = 0;
	if (size > 5 && size <= 16)
		range = 5;
	else if ((size > 16 && size <= 100) || (size >= 100 && size < 500))
		range = 15;
	else if (size >= 500)
		range = 35;
	return (range);
}

void	ft_final_operation(int *a, int *b, int *size_a, int *size_b)
{
	int	i;
	int	great;

	while (*size_b)
	{
		i = (*size_b / 2);
		great = the_great(b, *size_b);
		if (great == 0)
			ft_pa(a, b, size_a, size_b);
		else if (great < i)
		{
			while (great > 0)
			{
				ft_rb(b, *size_b);
				great--;
			}
			ft_pa(a, b, size_a, size_b);
		}
		else if (great >= i)
			ft_norminette_help(a, b, size_a, size_b);
	}
}

void	ft_norminette_help(int *a, int *b, int *size_a, int *size_b)
{
	int	great;

	great = the_great(b, *size_b);
	while (great < *size_b)
	{
		ft_rrb(b, *size_b);
		great++;
	}
	ft_pa(a, b, size_a, size_b);
}
