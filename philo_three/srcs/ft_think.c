/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:38:41 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 14:56:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_think(t_philo *philo)
{
	long	timestamp;
	long	remaining;

	timestamp = ft_get_timestamp(philo);
	remaining = philo->time_limits[DIED] - timestamp;
	ft_output(philo, "is thinking");
	if (remaining > philo->time_limits[EAT])
		ft_wait(philo, philo->time_limits[EAT]);
	philo->state = FORK;
}
