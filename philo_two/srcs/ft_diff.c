/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diff.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 13:39:55 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 14:41:21 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

inline int	ft_diff(struct timeval *n1, struct timeval *n2)
{
	return (ft_time_to_milli(n1) - ft_time_to_milli(n2));
}
