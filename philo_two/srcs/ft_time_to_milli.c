/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time_to_milli.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:37:37 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/02 16:18:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

long int	ft_time_to_milli(struct timeval *time)
{
	return (time->tv_usec * 0.001 + time->tv_sec * 1000);
}
