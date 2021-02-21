/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:03:51 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/21 17:03:56 by dboyer           ###   ########.fr       */
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

void	ft_controller(t_table *table)
{
	int	status;
	int	i;

	i = 0;
	while (i < table->n)
	{
		waitpid(-1, &status, 0);
		if (WEXITSTATUS(status) != 0)
		{
			sem_wait(table->lock_output);
			ft_kill_threads(table);
			sem_post(table->lock_output);
			break ;
		}
		i++;
	}
	ft_wait(1000);
	ft_clean_table(table);
}

void	ft_deploy_philo(t_table *table)
{
	int	i;

	if (table)
	{
		i = 0;
		while (i < (int)table->n)
		{
			ft_live(&table->philosophers[i], table);
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
