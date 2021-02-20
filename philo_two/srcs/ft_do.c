/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 14:51:41 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/18 19:30:36 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

void	ft_do(t_philo *philo)
{
	if (philo->state != DIED && philo->state != STOP)
	{
		ft_try_actions(philo);
		ft_do(philo);
	}
}
