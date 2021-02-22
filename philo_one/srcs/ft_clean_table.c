/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:37:06 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 12:40:08 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

static void	clean_arrays(t_table *table)
{
	int	i;

	if (table->forks && table->philosophers)
	{
		i = 0;
		while (i < table->n)
		{
			pthread_mutex_destroy(&table->forks[i]);
			pthread_mutex_destroy(&table->philosophers[i].lock_dead);
			i++;
		}
		free(table->forks);
		free(table->philosophers);
	}
}

void	ft_clean_table(t_table *table)
{
	if (table)
	{
		clean_arrays(table);
		pthread_mutex_destroy(&table->lock_output);
	}
}
