/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 13:35:22 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 12:40:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

static long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (ft_time_to_milli(&time));
}

void	ft_wait(int time)
{
	long	finish;

	finish = get_time() + time;
	while (get_time() < finish)
		usleep(1000);
}
