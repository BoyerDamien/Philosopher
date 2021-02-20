/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_take_forks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:27:51 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 16:52:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

static void	*check_time(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	while (p->forks_taken != 2)
	{
		if (ft_get_timestamp(p) > (int)p->time_limits[THINK])
		{
			ft_finish(p, DIED);
			return (NULL);
		}
	}
	return (NULL);
}

void	ft_take_forks(t_philo *philo)
{
	pthread_t	th;
	long int	remaining;

	if (philo->n_eat != 0)
	{
		if (philo->n_fork > 1)
		{
			philo->forks_taken = 0;
			pthread_create(&th, NULL, check_time, philo);
			sem_wait(philo->forks);
			ft_output(philo, "has taken a fork");
			sem_wait(philo->forks);
			philo->forks_taken = 2;
			ft_output(philo, "has taken a fork");
			philo->state = EAT;
		}
		else
		{
			remaining = philo->time_limits[DIED] - ft_get_timestamp(philo);
			ft_wait(philo, remaining);
			ft_finish(philo, DIED);
		}
	}
	else
		ft_finish(philo, STOP);
}
