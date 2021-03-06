/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:03:51 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 20:05:56 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_three.h"

void	ft_controller(t_table *table)
{
	int	status;

	status = 0;
	while (waitpid(-1, &status, 0) > 0)
	{
		if (WEXITSTATUS(status) == 1)
			ft_kill_threads(table);
	}
	ft_clean_sem(table);
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
