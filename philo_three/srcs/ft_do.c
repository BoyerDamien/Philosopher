/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:51:41 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 11:43:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

const t_actions	g_actions[4] = {
	ft_think,
	ft_take_forks,
	ft_eat,
	ft_sleep,
};

inline void	ft_do(t_philo *philo)
{
	gettimeofday(&philo->current_time, NULL);
	while (philo->state != DIED && philo->state != STOP && *philo->alive)
		ft_try_actions(philo, g_actions[philo->state]);
	if (philo->n_fork == 2)
	{
		sem_post(philo->forks);
		sem_post(philo->forks);
	}
}
