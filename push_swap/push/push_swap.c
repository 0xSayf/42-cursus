/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:17:05 by sahamzao          #+#    #+#             */
/*   Updated: 2024/08/04 20:44:42 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	go_sort(int *a, int *b, int *size_a, int *size_b)
{
	if (check_ranking(a, *size_a) == 0 || *size_a == 1)
		return (0);
	if (*size_a == 1)
		return (0);
	else if (*size_a == 2 && (a[0] > a[1]))
		ft_rra(a, *size_a);
	else if (*size_a == 3)
		go_3_numbers(a, size_a);
	else if (*size_a == 5 || *size_a == 4)
		go_5_numbers(a, b, size_a, size_b);
	else if (*size_a > 5)
		go_up_to_5(a, b, size_a, size_b);
	return (1);
}

void	go_3_numbers(int *a, int *size_a)
{
	if (a[0] > a[1] && a[0] < a[2])
		ft_sa(a, *size_a);
	else if (a[0] > a[1] && a[0] > a[2] && a[1] > a[2])
	{
		ft_sa(a, *size_a);
		ft_rra(a, *size_a);
	}
	else if (a[1] < a[0] && a[1] < a[2] && a[0] > a[2])
		ft_ra(a, *size_a);
	else if (a[1] > a[0] && a[1] > a[2] && a[2] > a[0])
	{
		ft_sa(a, *size_a);
		ft_ra(a, *size_a);
	}
	else if (a[1] > a[0] && a[1] > a[2] && a[2] < a[0])
		ft_rra(a, *size_a);
}

int	check_ranking(int *str, int numbers)
{
	int	i;

	i = 0;
	while (i < numbers - 1)
	{
		if (str[i] > str[i + 1])
			return (1);
		i++;
	}
	return (0);
}
