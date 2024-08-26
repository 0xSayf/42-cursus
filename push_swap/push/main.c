/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 14:47:39 by sahamzao          #+#    #+#             */
/*   Updated: 2024/08/11 18:55:43 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*allocation(int ac, char **av)
{
	int		i;
	int		*a;
	int		j;
	char	**malloca;
	int		k;

	a = malloc((ft_counta(ac, av)) * sizeof(int));
	i = 1;
	k = 0;
	while (i < ac)
	{
		j = 0;
		malloca = ft_split(av[i], ' ');
		while (malloca[j] && (k < ft_counta(ac, av)))
		{
			a[k] = ft_atoi(malloca[j]);
			j++;
			k++;
		}
		i++;
		ft_freeing(malloca);
	}
	return (a);
}

int	ft_counta(int ac, char **av)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (i < ac)
	{
		size = size + ft_count(av[i], ' ');
		i++;
	}
	return (size);
}

int	chek_error(char **str, int ac)
{
	char	**maal;
	int		j;
	t_node	t_node;

	t_node.i[0] = 1;
	while (t_node.i[0] < ac)
	{
		j = 0;
		maal = ft_split(str[t_node.i[0]], ' ');
		if (ft_just_for_norminette(maal) == 0)
		{
			ft_freeing(maal);
			return (0);
		}
		(t_node.i[0])++;
		ft_freeing(maal);
	}
	return (1);
}

int	ft_chek_double(int *str, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (str[j] == str[i])
			{
				write(2, "Error1\n", ft_strlen("Errorx\n"));
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	int	*stack_a;
	int	*stack_b;
	int	numbers_in_stack_b[1];
	int	numbers_in_stack_a[1];

	numbers_in_stack_b[0] = 0;
	numbers_in_stack_a[0] = ft_counta(ac, av);
	if (ft_counta(ac, av) == 0 || ft_chek(av) == 0 || chek_error(av, ac) == 0)
		return (0);
	stack_b = malloc(ft_counta(ac, av) * sizeof(int));
	stack_a = allocation(ac, av);
	if (ft_chek_double(stack_a, numbers_in_stack_a[0]) == 0)
	{
		ft_freee(stack_a, stack_b);
		return (0);
	}
	if (go_sort(stack_a, stack_b, &numbers_in_stack_a[0],
			&numbers_in_stack_b[0]) == 0)
	{
		ft_freee(stack_a, stack_b);
		return (0);
	}
	ft_freee(stack_a, stack_b);
}
