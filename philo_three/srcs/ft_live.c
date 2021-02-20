/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:45:30 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/18 20:33:07 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

static void	*run(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	p->doAction(p);
	return (NULL);
}

void	ft_live(t_philo *philo, t_table *table)
{
	philo->process = fork();
	if (philo->process == 0)
	{
		run(philo);
		ft_clean_table(table);
		exit(0);
	}
}
