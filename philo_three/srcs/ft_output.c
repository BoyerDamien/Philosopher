/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 18:47:59 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/23 16:14:04 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_output(t_philo *philo, char *msg)
{
	int	timestamp;

	timestamp = ft_get_timestamp(philo);
	sem_wait(philo->lock_output);
	printf("%d -- Philo %u %s\n", timestamp, philo->num, msg);
	sem_post(philo->lock_output);
}
