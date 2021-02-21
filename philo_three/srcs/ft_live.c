/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:45:30 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 16:58:47 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

inline static void	*run(void *philo)
{
	t_philo	*p;

	p = (t_philo *)philo;
	ft_do(p);
	return (NULL);
}

void	ft_live(t_philo *philo, t_table *table)
{
	philo->process = fork();
	if (philo->process == 0)
	{
		run(philo);
		if (philo->state == DIED)
		{
			ft_clean_table(table);
			exit(1);
		}
		ft_clean_table(table);
		exit(0);
	}
	else if (philo->process < 0)
	{
		ft_clean_table(table);
		perror("Fork !");
		exit(-1);
	}
}
