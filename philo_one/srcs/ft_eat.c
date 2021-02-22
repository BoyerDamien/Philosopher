/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:47:44 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 12:40:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

void	ft_eat(t_philo *philo)
{
	ft_output(philo, "is eating");
	ft_wait(philo->time_limits[EAT]);
	pthread_mutex_unlock(philo->forks[1]);
	pthread_mutex_unlock(philo->forks[0]);
	if (philo->n_eat > 0)
		philo->n_eat--;
	philo->state = SLEEP;
}
