/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:27:51 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 15:26:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

inline static void	*check_time(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (p->forks_taken != 2)
	{
		if (ft_get_timestamp(p) > p->time_limits[DIED])
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
	pthread_t	th;

	philo->forks_taken = 0;
	pthread_create(&th, NULL, check_time, philo);
	pthread_detach(th);
	sem_wait(philo->forks);
	ft_output(philo, "has taken a fork");
	sem_wait(philo->forks);
	philo->forks_taken = 2;
	ft_output(philo, "has taken a fork");
}

inline void	ft_take_forks(t_philo *philo)
{
	long	remaining;

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
