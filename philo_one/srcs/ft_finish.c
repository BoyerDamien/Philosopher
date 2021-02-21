/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:30:44 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 14:56:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

inline static void	output(t_philo *philo, char *msg)
{
	long	timestamp;

	timestamp = ft_get_timestamp(philo);
	printf("%ld -- Philo %u %s\n", timestamp, philo->num, msg);
}

void	ft_finish(t_philo *philo, t_philo_state state)
{
	philo->state = state;
	pthread_mutex_lock(philo->lock_output);
	if (*philo->alive)
	{
		if (state == DIED)
		{
			output(philo, "has died");
			*(philo->alive) = false;
		}
		else if (state == STOP)
			output(philo, "has finished");
	}
	pthread_mutex_unlock(philo->lock_output);
}
