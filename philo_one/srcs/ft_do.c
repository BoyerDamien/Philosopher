/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:51:41 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 16:43:40 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

inline void	ft_do(t_philo *philo)
{
	t_philo		*philos;
	int			id;
	int			n;

	id = philo->num;
	n = philo->table->n;
	philos = philo->table->philosophers;
	gettimeofday(&philo->current_time, NULL);
	while (philo->state != DIED && philo->state != STOP && *philo->alive)
		ft_try_actions(philo);
	pthread_mutex_unlock(&philo->lock_dead);
	pthread_mutex_unlock(&philos[(id) % n].lock_dead);
	pthread_mutex_unlock(philo->forks[0]);
	pthread_mutex_unlock(philo->forks[1]);
}
