/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:30:44 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 15:44:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

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
			ft_clean_table(philo->table);
			exit(1);
		}
		else if (state == STOP)
			output(philo, "has finished");
	}
	sem_post(philo->lock_output);
}
