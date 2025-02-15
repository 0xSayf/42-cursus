/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mben-abb <mben-abb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 23:35:25 by mben-abb          #+#    #+#             */
/*   Updated: 2025/02/10 23:35:28 by mben-abb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_if_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_num(char c)
{
	if (c < 48 || c > 57)
		return (1);
	return (0);
}

int	ft_aatooi(const char *str)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	if (ft_is_num(*str))
		return (-493999);
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + *str - 48;
		str++;
	}
	return (sign * res);
}

void	ft_exit(char **args)
{
	long	stat;

	args++;
	if (!*args)
		exit(0);
	stat = ft_aatooi(*args);
	if (*args && (*(args + 1)))
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		exit(1);
	}
	if (stat == -493999)
	{
		ft_putstr_fd("exit: invalid number\n", 2);
		exit(255);
	}
	else
		exit(stat);
}
