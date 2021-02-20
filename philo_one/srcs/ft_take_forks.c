/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:27:51 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 19:45:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

inline static void	*check_time(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (p->forks_taken != 2)
	{
		if (ft_get_timestamp(p) > p->time_limits[DIED] + 3)
		{
			ft_finish(p, DIED);
			return (NULL);
		}
		ft_wait(1);
	}
	return (NULL);
}

inline static void	take_forks(t_philo *philo)
{
	t_philo		*philos;
	int			id;
	int			n;
	pthread_t	th;

	id = philo->num;
	n = philo->table->n;
	philos = philo->table->philosophers;
	philo->forks_taken = 0;
	pthread_create(&th, NULL, check_time, philo);
	pthread_detach(th);
	pthread_mutex_lock(&philo->lock_dead);
	pthread_mutex_lock(&philos[id % n].lock_dead);
	pthread_mutex_lock(philo->forks[0]);
	ft_output(philo, "has taken a fork");
	pthread_mutex_lock(philo->forks[1]);
	philo->forks_taken = 2;
	ft_output(philo, "has taken a fork");
}

inline void	ft_take_forks(t_philo *philo)
{
	long int	remaining;

	if (philo->n_fork > 1)
	{
		take_forks(philo);
		philo->state = EAT;
		gettimeofday(&philo->current_time, NULL);
	}
	else
	{
		remaining = philo->time_limits[DIED] - ft_get_timestamp(philo);
		ft_wait(remaining);
		ft_finish(philo, DIED);
	}
}
