/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:47:03 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 12:04:24 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

static void	setForks(t_philo *new, const int n, pthread_mutex_t *forks)
{
	new->forks[1] = &forks[new->num % n];
	new->forks[0] = &forks[new->num - 1];
}

static void	set_arrays(t_philo *this, const t_args *args)
{
	this->time_limits[DIED] = args->time_to_die + 5;
	this->time_limits[EAT] = args->time_to_eat;
	this->time_limits[SLEEP] = args->time_to_sleep;
	this->time_limits[THINK] = 0;
	this->time_limits[STOP] = 0;
	this->time_limits[FORK] = 0;
}

t_philo	ft_philo(const t_args *args, const unsigned int num, \
					pthread_mutex_t *forks)
{
	t_philo	new;

	new.num = num + 1;
	new.n_fork = args->n_philo;
	new.n_eat = args->n_eat;
	if (new.num % 2 == 0)
		new.state = FORK;
	else
		new.state = SLEEP;
	new.forks_taken = 0;
	set_arrays(&new, args);
	setForks(&new, args->n_philo, forks);
	pthread_mutex_init(&new.lock_dead, NULL);
	return (new);
}
