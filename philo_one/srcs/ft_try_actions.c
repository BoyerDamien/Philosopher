/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:12:49 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 12:11:37 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

inline void	ft_try_actions(t_philo *philo, void (*action)(t_philo *philo))
{
	long int	timestamp;
	long int	remain;

	timestamp = ft_get_timestamp(philo);
	if (timestamp > philo->time_limits[DIED])
	{
		ft_finish(philo, DIED);
		return ;
	}
	if (philo->n_eat == 0)
	{
		ft_finish(philo, STOP);
		return ;
	}
	remain = ft_get_timestamp(philo) + philo->time_limits[philo->state];
	if (remain > philo->time_limits[DIED])
	{
		ft_wait(philo->time_limits[DIED] - timestamp);
		ft_finish(philo, DIED);
		return ;
	}
	action(philo);
}
