/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:10:34 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 16:44:20 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

inline void	ft_sleep(t_philo *philo)
{
	ft_output(philo, "is sleeping");
	usleep(philo->time_limits[SLEEP] * 1000);
	philo->state = THINK;
}
