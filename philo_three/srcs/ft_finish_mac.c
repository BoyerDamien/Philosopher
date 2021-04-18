/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_finish_mac.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:30:44 by dboyer            #+#    #+#             */
/*   Updated: 2021/04/18 11:54:24 by dess             ###   ########.fr       */
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
	if (state == DIED)
	{
		output(philo, "has died");
		ft_clean_table(philo->table);
		exit(1);
	}
	else if (state == STOP)
		output(philo, "has finished");
	sem_post(philo->lock_output);
	exit(0);
}
