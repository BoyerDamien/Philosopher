/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:51:41 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 15:31:01 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

const t_actions	g_actions[4] = {
	ft_think,
	ft_take_forks,
	ft_eat,
	ft_sleep,
};

inline void	ft_do(t_philo *philo)
{
	gettimeofday(&philo->current_time, NULL);
	while (philo->state != DIED && philo->state != STOP && *philo->alive)
		ft_try_actions(philo, g_actions[philo->state]);
	sem_post(philo->forks);
	sem_post(philo->forks);
}
