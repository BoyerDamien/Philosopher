/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:08:03 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/02 15:20:10 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo_one.h"

t_bool	ft_check_args(int argc, const char **argv)
{
	int	i;

	if (argc >= 5)
	{
		i = 1;
		while (i < argc)
		{
			if (!ft_isnum(argv[i]))
				return (false);
			i++;
		}
		return (true);
	}
	return (false);
}
