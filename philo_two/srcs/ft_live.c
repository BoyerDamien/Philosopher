/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:45:30 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/18 20:19:38 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

static void	*run(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	p->doAction(p);
	return (NULL);
}

void	ft_live(t_philo *philo)
{
	pthread_create(&philo->th, NULL, run, philo);
	pthread_detach(philo->th);
}
