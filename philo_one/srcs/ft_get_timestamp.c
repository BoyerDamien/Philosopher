/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_timestamp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:48:30 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 16:43:55 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

inline static int	diff(struct timeval *n1, struct timeval *n2)
{
	return (ft_time_to_milli(n1) - ft_time_to_milli(n2));
}

inline int	ft_get_timestamp(t_philo *philo)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (diff(&time, &philo->current_time));
}
