/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:30:44 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 12:40:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

static void	output(t_philo *philo, char *msg)
{
	long	timestamp;

	timestamp = ft_get_timestamp(philo);
	printf("%ld -- Philo %u %s\n", timestamp, philo->num, msg);
}

void	ft_finish(t_philo *philo, t_philo_state state)
{
	philo->state = state;
	sem_wait(philo->lock_output);
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
	sem_post(philo->lock_output);
}
