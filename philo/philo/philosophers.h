/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sahamzao <sahamzao@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 11:06:18 by sahamzao          #+#    #+#             */
/*   Updated: 2024/11/05 11:05:04 by sahamzao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_info
{
	size_t			time_while_eating;
	size_t			time_while_sleeping;
	size_t			time_to_die;
	size_t			start_time;
	int				number_of_threads;
	int				number_of_meals;
	int				number_of_forks;
	pthread_mutex_t	*printing;
	pthread_mutex_t	*dead;
	pthread_mutex_t	*forks;
	pthread_mutex_t	meal;
	pthread_mutex_t	time;
	int				full;
	int				deads;

}					t_info;

typedef struct s_philo
{
	pthread_t		thread;
	size_t			timing;
	size_t			meals;
	int				id;
	size_t			start_time;
	pthread_mutex_t	gta;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	t_info			*info;
}					t_philo;

int					ft_checking(t_philo *philo, t_info *info);
size_t				ft_atoi(const char *str);
void				*ft_routine(void *arg);
size_t				ft_get_time(void);
int					ft_check_meal(t_philo *philo, t_info *info);
int					ft_eating(t_philo *philo);
int					ft_sleep(t_philo *philo);
void				ft_printing(t_philo *philo, char *str);
int					ft_check(char **str);
void				ft_thinking(t_philo *philo);
int					ft_double_chek(t_philo *philo, t_info *info);
t_philo				*ft_init(t_info *info, char **av, int ac);
int					ft_usleep(size_t milliseconds, t_philo *philo);
int					ft_raw_daw(t_philo *philo);
void				ft_terminate(t_philo *philo, t_info *info);
void				ft_destroy_mutexe(t_philo *philo, t_info *info);

#endif