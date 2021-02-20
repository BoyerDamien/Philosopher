/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 16:14:34 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/20 17:08:11 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
typedef enum e_philo_state
{
	THINK,
	EAT,
	SLEEP,
	FORK,
	DIED,
	STOP
}	t_philo_state;

typedef enum e_bool
{
	false,
	true
}	t_bool;

/******************************************************************************
 *				Args object
 *****************************************************************************/
typedef struct s_args
{
	unsigned int	n_philo;
	unsigned int	time_to_die;
	unsigned int	time_to_eat;
	unsigned int	time_to_sleep;
	unsigned int	n_eat;
}	t_args;

/******************************************************************************
 *				Philosopher object
 *****************************************************************************/
struct			s_philo;
struct			s_table;
typedef void	(*t_actions)(struct s_philo *philo);

typedef struct s_philo
{
	int				num;
	int				n_fork;
	int				forks_taken;
	int				n_eat;
	int				time_limits[6];
	struct s_table	*table;
	struct timeval	current_time;
	t_bool			*alive;
	t_actions		actions[4];
	t_philo_state	state;
	pthread_t		th;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	*forks[2];
	pthread_mutex_t	*lock_output;

}	t_philo;

/*
 *	Philosopher member functions
 */

t_philo		ft_philo(const t_args *args, const unsigned int num, \
						struct s_table *table);
void		ft_take_forks(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_do(t_philo *philo);
void		ft_live(t_philo *philo);
void		ft_sleep(t_philo *philo);

/******************************************************************************
 *				Table object
 *****************************************************************************/
typedef struct s_table
{
	int				n;
	t_bool			alive;
	t_philo			*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock_dead;
	pthread_mutex_t	lock_output;
}	t_table;

/*
 *	Table member functions
 */

t_table		ft_table(int argc, const char **argv);
void		ft_clean_table(t_table *table);

/***************************************************************************
 * 							Utils functions
 **************************************************************************/
int			ft_atoi(const char *str);
t_bool		ft_isspace(const char c);
t_bool		ft_isdigit(int c);
t_bool		ft_cinset(const char c, const char *set);
t_bool		ft_isnum(const char *str);
t_bool		ft_check_args(int argc, const char **argv);
t_args		ft_parse_args(int argc, const char **argv);

long int	ft_time_to_milli(struct timeval *time);

int			ft_get_timestamp(t_philo *philo);

void		ft_output(t_philo *philo, char *msg);
void		ft_finish(t_philo *philo, t_philo_state state);
void		ft_try_actions(t_philo *philo);
void		ft_wait(int time);
#endif
