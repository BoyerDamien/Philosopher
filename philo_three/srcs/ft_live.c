/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 15:45:30 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 19:08:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_live(t_philo *philo, t_table *table)
{
	philo->process = fork();
	if (philo->process == 0)
		ft_do(philo);
	else if (philo->process < 0)
	{
		ft_clean_table(table);
		perror("Fork !");
		exit(-1);
	}
}
