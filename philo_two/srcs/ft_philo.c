/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 14:47:03 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 14:57:23 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_two.h"

static void	set_methods(t_philo *this)
{
	this->doAction = ft_do;
	this->actions[EAT] = ft_eat;
	this->actions[SLEEP] = ft_sleep;
	this->actions[THINK] = ft_think;
	this->actions[FORK] = ft_take_forks;
	this->live = ft_live;
	this->take_forks = ft_take_forks;
}

t_philo	ft_philo(const t_args *args, const int num, \
					sem_t *forks)
{
	t_philo	new;

	new.num = num + 1;
	new.n_fork = args->n_philo;
	new.time_limits[THINK] = args->time_to_die;
	new.time_limits[EAT] = args->time_to_eat;
	new.time_limits[SLEEP] = args->time_to_sleep;
	new.n_eat = args->n_eat;
	if ((num + 1) % 2 == 0)
		new.state = THINK;
	else
		new.state = SLEEP;
	new.forks_taken = 0;
	new.forks = forks;
	set_methods(&new);
	gettimeofday(&new.current_time, NULL);
	return (new);
}
