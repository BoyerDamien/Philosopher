/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_sem.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 14:25:57 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 20:11:02 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_clean_sem(t_table *table)
{
	sem_close(table->lock_output);
	sem_close(table->forks);
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_OUTPUT);
}
