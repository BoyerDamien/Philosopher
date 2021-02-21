/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:30:08 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 19:22:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

static t_philo	*ft_build_philos(const t_args *args, t_table *table)
{
	t_philo			*philos;
	int				i;

	philos = (t_philo *)malloc(args->n_philo * sizeof(t_philo));
	if (philos)
	{
		i = 0;
		while (i < args->n_philo)
		{
			philos[i] = ft_philo(args, i, table->forks);
			philos[i].lock_output = &table->lock_output;
			philos[i].alive = &table->alive;
			i++;
		}
	}
	return (philos);
}

static pthread_mutex_t	*ft_build_forks(const t_args *args)
{
	pthread_mutex_t	*forks;
	int				i;

	forks = (pthread_mutex_t *)malloc(args->n_philo * sizeof(pthread_mutex_t));
	if (forks)
	{
		i = 0;
		while (i < args->n_philo)
		{
			pthread_mutex_init(&forks[i], NULL);
			i++;
		}
	}
	return (forks);
}

t_table	ft_table(int argc, const char **argv)
{
	t_table	new;
	t_args	args;

	args = ft_parse_args(argc, argv);
	pthread_mutex_init(&new.lock_output, NULL);
	new.alive = true;
	new.n = args.n_philo;
	new.forks = ft_build_forks(&args);
	new.philosophers = ft_build_philos(&args, &new);
	return (new);
}
