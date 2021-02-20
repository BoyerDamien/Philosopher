/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 15:10:34 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 19:39:57 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

inline void	ft_sleep(t_philo *philo)
{
	ft_output(philo, "is sleeping");
	ft_wait(philo->time_limits[SLEEP]);
	philo->state = THINK;
}
