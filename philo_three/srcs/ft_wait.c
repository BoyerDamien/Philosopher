/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:35:22 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/16 17:04:01 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

long int	ft_wait(t_philo *philo, int time)
{
	usleep(time * 1000);
	return (ft_get_timestamp(philo));
}
