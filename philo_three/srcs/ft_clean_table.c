/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clean_table.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 15:37:06 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 19:06:09 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_clean_table(t_table *table)
{
	if (table && table->philosophers)
	{
		ft_clean_sem(table);
		free(table->philosophers);
		table->philosophers = NULL;
		table = NULL;
	}
}
