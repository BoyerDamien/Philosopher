/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/18 20:34:05 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/18 20:34:13 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <fcntl.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define SEM_FORKS "forks"
# define SEM_DEAD "dead"
# define SEM_OUTPUT "output"

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
	unsigned int	num;
	unsigned int	n_fork;
	unsigned int	forks_taken;
	unsigned int	n_eat;
	unsigned int	time_limits[3];
	struct timeval	current_time;
	struct s_table	*table;
	sem_t			*forks;
	sem_t			*lock_dead;
	sem_t			*lock_output;
	pid_t			process;
	t_philo_state	state;
	t_actions		actions[4];

	void	(*doAction)(struct s_philo *philo);
	void	(*live)(struct s_philo *philo, struct s_table *table);
	void	(*take_forks)(struct s_philo *philo);
	void	(*change_state)(struct s_philo *philo, t_philo_state state);
}	t_philo;

/*
 *	Philosopher member functions
 */

t_philo		ft_philo(const t_args *args, const unsigned int num, \
						sem_t *forks);
void		ft_take_forks(t_philo *philo);
void		ft_think(t_philo *philo);
void		ft_eat(t_philo *philo);
void		ft_do(t_philo *philo);
void		ft_sleep(t_philo *philo);
/******************************************************************************
 *				Table object
 *****************************************************************************/
typedef struct s_table
{
	t_philo			*philosophers;
	unsigned int	n;
	sem_t			*forks;
	sem_t			*lock_dead;
	sem_t			*lock_output;

	void	(*clean)(struct s_table *table);
	void	(*wake_philos)(struct s_table *table);
}	t_table;

/*
 *	Table member functions
 */

t_table		ft_table(int argc, const char **argv);
void		ft_clean_table(t_table *table);
void		ft_live(t_philo *philo, t_table *table);
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
long int	ft_wait(t_philo *philo, int time);

int			ft_get_timestamp(t_philo *philo);

void		ft_output(t_philo *philo, char *msg);
void		ft_finish(t_philo *philo, t_philo_state state);
void		ft_try_actions(t_philo *philo);
#endif
