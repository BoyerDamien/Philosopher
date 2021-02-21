/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:30:08 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 15:34:03 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

static t_philo	*ft_build_philos(const t_args *args, t_table *table)
{
	t_philo		*philos;
	int			i;

	philos = (t_philo *)malloc(args->n_philo * sizeof(t_philo));
	if (philos)
	{
		i = 0;
		while (i < args->n_philo)
		{
			philos[i] = ft_philo(args, i, table->forks);
			philos[i].lock_output = table->lock_output;
			philos[i].alive = &table->alive;
			i++;
		}
	}
	return (philos);
}

static void	check_sem(void)
{
	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_OUTPUT);
}

t_table	ft_table(int argc, const char **argv)
{
	t_table	new;
	t_args	args;

	args = ft_parse_args(argc, argv);
	new.alive = true;
	new.n = args.n_philo;
	check_sem();
	new.forks = sem_open(SEM_FORKS, O_CREAT | O_EXCL, 0644, args.n_philo);
	new.lock_output = sem_open(SEM_OUTPUT, O_CREAT | O_EXCL, 0644, 1);
	new.philosophers = ft_build_philos(&args, &new);
	return (new);
}
