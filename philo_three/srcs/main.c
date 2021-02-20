/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:03:51 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 19:40:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

t_bool	ft_is_died(t_table *table)
{
	int		i;
	t_philo	philo;

	if (table)
	{
		i = 0;
		while (i < (int)table->n)
		{
			philo = table->philosophers[i];
			if (philo.state == DIED || philo.state == STOP)
				return (true);
			i++;
		}
	}
	return (false);
}

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
	ft_wait(1000);
}

void	ft_controller(t_table *table)
{
	int	status;

	waitpid(-1, &status, 0);
	ft_kill_threads(table);
	table->clean(table);
}

void	ft_deploy_philo(t_table *table)
{
	int	i;

	if (table)
	{
		i = 0;
		while (i < (int)table->n)
		{
			table->philosophers[i].live(&table->philosophers[i], table);
			i++;
		}
	}
}

int	main(int argc, const char *argv[])
{
	t_table	table;

	(void)argc;
	if (!ft_check_args(argc, argv))
	{
		printf("Invalid arguments");
		exit(EXIT_FAILURE);
	}
	table = ft_table(argc, argv);
	ft_deploy_philo(&table);
	ft_controller(&table);
	return (0);
}
