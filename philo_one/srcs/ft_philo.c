/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:47:03 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 19:54:28 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

static void	setForks(t_philo *new, pthread_mutex_t *forks)
{
	int	index;

	index = new->num % new->table->n;
	new->forks[1] = &forks[index];
	new->forks[0] = &forks[new->num - 1];
}

static void	set_arrays(t_philo *this, const t_args *args)
{
	this->actions[EAT] = ft_eat;
	this->actions[SLEEP] = ft_sleep;
	this->actions[THINK] = ft_think;
	this->actions[FORK] = ft_take_forks;
	this->time_limits[DIED] = args->time_to_die + 4;
	this->time_limits[EAT] = args->time_to_eat;
	this->time_limits[SLEEP] = args->time_to_sleep;
	this->time_limits[THINK] = 0;
	this->time_limits[STOP] = 0;
	this->time_limits[FORK] = 0;
}

t_philo	ft_philo(const t_args *args, const unsigned int num, \
					t_table *table)
{
	t_philo	new;

	new.num = num + 1;
	new.table = table;
	new.n_fork = args->n_philo;
	new.n_eat = args->n_eat;
	if (new.num % 2 == 0)
		new.state = FORK;
	else
		new.state = SLEEP;
	new.forks_taken = 0;
	new.lock_output = &table->lock_output;
	new.alive = &table->alive;
	set_arrays(&new, args);
	setForks(&new, table->forks);
	pthread_mutex_init(&new.lock_dead, NULL);
	return (new);
}
