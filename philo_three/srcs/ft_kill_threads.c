/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_kill_threads.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 17:26:50 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 19:18:29 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_kill_threads(t_table *table)
{
	int	i;

	if (table)
	{
		i = 0;
		while (i < (int)table->n)
		{
			kill(table->philosophers[i].process, SIGKILL);
			i++;
		}
	}
}
