/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:33:05 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/04 11:06:48 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

t_args	ft_parse_args(int argc, const char **argv)
{
	t_args	new;

	new.n_philo = ft_atoi(argv[1]);
	new.time_to_die = ft_atoi(argv[2]);
	new.time_to_eat = ft_atoi(argv[3]);
	new.time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		new.n_eat = ft_atoi(argv[5]);
	else
		new.n_eat = -1;
	return (new);
}
