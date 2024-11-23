/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 12:28:37 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/05 11:26:49 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_double_chek(t_philo *philo, t_info *info)
{
	int	i;
	int	b;
	int	swap;

	b = 0;
	i = 0;
	while (i < info->number_of_threads)
	{
		swap = philo[i].meals;
		if (swap >= info->number_of_meals)
			b++;
		i++;
	}
	if (b == info->number_of_threads)
	{
		pthread_mutex_lock(&philo->info->meal);
		philo->info->full = 1;
		pthread_mutex_unlock(&philo->info->meal);
		return (-1);
	}
	return (0);
}

void	ft_printing(t_philo *philo, char *str)
{
	pthread_mutex_lock(philo->info->printing);
	pthread_mutex_lock(philo->info->dead);
	if (philo->info->deads == 0)
		printf("%lu %d %s\n", ft_get_time() - philo->info->start_time,
			philo->id, str);
	pthread_mutex_unlock(philo->info->dead);
	pthread_mutex_unlock(philo->info->printing);
}

int	ft_sleep(t_philo *philo)
{
	ft_printing(philo, "is sleeping");
	if (ft_usleep(philo->info->time_while_sleeping, philo) == -1)
		return (-1);
	return (0);
}

int	ft_checking(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_threads)
	{
		pthread_mutex_lock(&info->time);
		if ((ft_get_time() - philo[i].timing) >= info->time_to_die)
		{
			pthread_mutex_unlock(&info->time);
			pthread_mutex_lock(philo[i].info->dead);
			philo->info->deads = 1;
			pthread_mutex_unlock(philo[i].info->dead);
			printf("%lu %d %s\n", ft_get_time() - philo->info->start_time, 
				philo[i].id, "died");
			return (-1);
		}
		pthread_mutex_unlock(&info->time);
		i++;
	}
	if (info->number_of_meals > 0)
	{
		if (ft_double_chek(philo, info) == -1)
			return (-1);
	}
	return (0);
}

int	ft_eating(t_philo *philo)
{
	pthread_mutex_lock(philo->l_fork);
	ft_printing(philo, "has taken a fork");
	if (philo->info->number_of_threads == 1)
		return (-1);
	pthread_mutex_lock(philo->r_fork);
	ft_printing(philo, "has taken a fork");
	ft_printing(philo, "is eating");
	pthread_mutex_lock(&philo->info->time);
	philo->timing = ft_get_time();
	pthread_mutex_unlock(&philo->info->time);
	if (ft_usleep(philo->info->time_while_eating, philo) == -1)
	{
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (-1);
	}
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	if (ft_raw_daw(philo) == -1)
		return (-1);
	return (0);
}
