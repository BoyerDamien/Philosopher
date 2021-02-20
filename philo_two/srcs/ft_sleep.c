/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:10:34 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 16:52:30 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void	ft_sleep(t_philo *philo)
{
	ft_output(philo, "is sleeping");
	if (philo->time_limits[SLEEP] <= philo->time_limits[DIED])
	{
		ft_wait(philo, philo->time_limits[SLEEP]);
		philo->state = THINK;
	}
	else
	{
		ft_wait(philo, philo->time_limits[DIED]);
		ft_finish(philo, DIED);
	}
}
