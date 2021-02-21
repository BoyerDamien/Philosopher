/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:37:06 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 16:23:25 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_clean_table(t_table *table)
{
	if (table)
	{
		sem_unlink(SEM_FORKS);
		sem_unlink(SEM_OUTPUT);
		sem_close(table->lock_output);
		sem_close(table->forks);
		if (table->philosophers)
		{
			free(table->philosophers);
			table->philosophers = NULL;
		}
		table = NULL;
	}
}
