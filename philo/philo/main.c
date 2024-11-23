/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 18:19:11 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/05 11:12:21 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
	{
		if (ft_sleep(philo) == -1)
			return (NULL);
	}
	while (1)
	{
		if (ft_eating(philo) == -1)
			return (NULL);
		philo->meals++;
		if (ft_raw_daw(philo) == -1)
			break ;
		if (ft_sleep(philo) == -1)
			return (NULL);
		ft_thinking(philo);
	}
	return (NULL);
}

t_philo	*ft_init(t_info *info, char **av, int ac)
{
	t_philo	*ret;

	info->number_of_threads = ft_atoi(av[1]);
	info->time_to_die = ft_atoi(av[2]);
	info->time_while_eating = ft_atoi(av[3]);
	info->time_while_sleeping = ft_atoi(av[4]);
	info->number_of_forks = info->number_of_threads;
	if (ac == 6)
		info->number_of_meals = ft_atoi(av[5]);
	else if (ac != 6)
		info->number_of_meals = -1;
	if (!info->number_of_meals || !info->number_of_threads)
		return (NULL);
	if (info->number_of_threads > 200 || info->time_to_die < 60
		|| info->time_while_eating < 60 || info->time_while_sleeping < 60)
		return (NULL);
	ret = malloc(sizeof(t_philo) * info->number_of_threads);
	info->forks = malloc(sizeof(pthread_mutex_t) * info->number_of_threads);
	info->printing = malloc(sizeof(pthread_mutex_t) * 1);
	info->dead = malloc(sizeof(pthread_mutex_t) * 1);
	pthread_mutex_init(info->dead, NULL);
	pthread_mutex_init(info->printing, NULL);
	return (ret);
}

void	ft_go(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	pthread_mutex_init(&info->time, NULL);
	pthread_mutex_init(&info->meal, NULL);
	pthread_mutex_init(&philo->gta, NULL);
	while (i < info->number_of_threads)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < info->number_of_threads)
	{
		philo[i].info = info;
		philo[i].id = i + 1;
		philo[i].meals = 0;
		philo[i].l_fork = &info->forks[i];
		philo[i].timing = ft_get_time();
		i++;
	}
	info->full = 0;
	info->deads = 0;
}

void	ft_create_threads(t_philo *philo, t_info *info)
{
	int	i;
	int	status;

	i = 0;
	info->start_time = ft_get_time();
	while (i < info->number_of_threads)
	{
		philo[i].r_fork = philo[(i + 1) % info->number_of_threads].l_fork;
		status = pthread_create(&philo[i].thread, NULL, ft_routine, &philo[i]);
		if (status)
			return ;
		i++;
	}
	while (1)
	{
		if (ft_checking(philo, info) == -1)
			break ;
	}
}

int	main(int ac, char **av)
{
	t_philo	*philo;
	t_info	info;

	philo = NULL;
	if (ac == 5 || ac == 6)
	{
		philo = ft_init(&info, av, ac);
		if (philo == NULL)
			return (0);
		ft_go(philo, &info);
		ft_create_threads(philo, &info);
		ft_terminate(philo, &info);
	}
}
