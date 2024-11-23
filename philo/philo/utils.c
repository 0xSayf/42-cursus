/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 11:28:06 by sahamzao          #+#    #+#             */
/*   Updated: 2024/10/20 18:05:39 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is__space(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

size_t	ft_atoi(const char *str)
{
	size_t	res;
	int		i;

	res = 0;
	i = 0;
	while (is__space(str[i]))
		i++;
	if (str[i] == '-')
		return (0);
	if (str[i] == '+')
		i++;
	while (str[i] >= 48 && str[i] <= 57)
	{
		res = (res * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] != '\0')
		return (0);
	return (res);
}

size_t	ft_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_thinking(t_philo *philo)
{
	ft_printing(philo, "is thinking");
}

int	ft_usleep(size_t milliseconds, t_philo *philo)
{
	size_t	start;

	start = ft_get_time();
	while ((ft_get_time() - start) < milliseconds)
	{
		pthread_mutex_lock(philo->info->dead);
		if (philo->info->deads == 1)
		{
			pthread_mutex_unlock(philo->info->dead);
			return (-1);
		}
		pthread_mutex_unlock(philo->info->dead);
		usleep(150);
	}
	return (0);
}
