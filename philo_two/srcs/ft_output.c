/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:47:59 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 14:56:32 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void	ft_output(t_philo *philo, char *msg)
{
	long	timestamp;

	sem_wait(philo->lock_dead);
	sem_wait(philo->lock_output);
	timestamp = ft_get_timestamp(philo);
	printf("%ld -- Philo %u %s\n", timestamp, philo->num, msg);
	sem_post(philo->lock_output);
	sem_post(philo->lock_dead);
}
