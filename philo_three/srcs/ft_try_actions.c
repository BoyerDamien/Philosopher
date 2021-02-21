/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:12:49 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 14:56:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_try_actions(t_philo *philo)
{
	long	timestamp;

	timestamp = ft_get_timestamp(philo);
	if (timestamp < philo->time_limits[DIED])
		philo->actions[philo->state](philo);
	else
		ft_finish(philo, DIED);
}
