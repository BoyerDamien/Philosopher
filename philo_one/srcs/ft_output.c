/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:47:59 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 10:20:56 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

inline void	ft_output(t_philo *philo, char *msg)
{
	int	timestamp;

	timestamp = ft_get_timestamp(philo);
	pthread_mutex_lock(philo->lock_output);
	if (*philo->alive)
		printf("%d -- Philo %u %s\n", timestamp, philo->num, msg);
	pthread_mutex_unlock(philo->lock_output);
}
