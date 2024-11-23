/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 14:55:44 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/05 11:06:35 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_raw_daw(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->meal);
	if (philo->info->full == 1)
	{
		pthread_mutex_unlock(&philo->info->meal);
		return (-1);
	}
	pthread_mutex_unlock(&philo->info->meal);
	return (0);
}

void	ft_destroy_mutexe(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_destroy(&info->time);
	pthread_mutex_destroy(info->dead);
	pthread_mutex_destroy(info->printing);
	while (i < info->number_of_forks)
	{
		pthread_mutex_destroy(&info->forks[i]);
		i++;
	}
	free(info->dead);
	free(info->printing);
	free(info->forks);
	free(philo);
}

void	ft_terminate(t_philo *philo, t_info *info)
{
	int	i;
	int	status;

	i = 0;
	while (i < info->number_of_threads)
	{
		status = pthread_join(philo[i].thread, NULL);
		if (status)
			return ;
		i++;
	}
	ft_destroy_mutexe(philo, info);
}
