/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 16:47:44 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 15:25:55 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

inline void	ft_eat(t_philo *philo)
{
	ft_output(philo, "is eating");
	ft_wait(philo->time_limits[EAT]);
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (philo->n_eat > 0)
		philo->n_eat--;
	philo->state = SLEEP;
}
