/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dboyer <dboyer@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/21 16:58:05 by dboyer            #+#    #+#             */
/*   Updated: 2021/02/22 11:46:59 by dboyer           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/errno.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>
# include <semaphore.h>
# include <fcntl.h>
# include <signal.h>

# define SEM_FORKS "forks"
# define SEM_OUTPUT "output"

typedef enum e_philo_state
{
	THINK,
	FORK,
	EAT,
	SLEEP,
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
	int	n_philo;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_eat;
}	t_args;

/******************************************************************************
 *				Philosopher object
 *****************************************************************************/
struct			s_table;
typedef struct s_philo
{
	int				num;
	int				n_fork;
	int				forks_taken;
	int				n_eat;
	int				time_limits[6];
	struct timeval	current_time;
	t_bool			*alive;
	t_philo_state	state;
	struct s_table	*table;
	pid_t			process;
	sem_t			*forks;
	sem_t			*lock_output;

}	t_philo;

typedef void	(*t_actions)(t_philo *philo);

/*
 *	Philosopher member functions
 */

t_philo		ft_philo(const t_args *args, const int num, \
						sem_t *forks);
void		ft_take_forks(t_philo *philo) __attribute__((hot));
void		ft_think(t_philo *philo) __attribute__((hot));
void		ft_eat(t_philo *philo) __attribute__((hot));
void		ft_do(t_philo *philo) __attribute__((hot));
void		ft_sleep(t_philo *philo) __attribute__((hot));

/******************************************************************************
 *				Table object
 *****************************************************************************/
typedef struct s_table
{
	int				n;
	t_bool			alive;
	t_philo			*philosophers;
	sem_t			*forks;
	sem_t			*lock_output;
}	t_table;

/*
 *	Table member functions
 */

t_table		ft_table(int argc, const char **argv);
void		ft_clean_table(t_table *table);

void		ft_live(t_philo *philo, t_table *table) __attribute__((hot));
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

long		ft_time_to_milli(struct timeval *time) __attribute__((pure));
int			ft_diff(struct timeval *n1, struct timeval *n2) \
				__attribute__((pure));
int			ft_get_timestamp(t_philo *philo) __attribute__((pure));

void		ft_output(t_philo *philo, char *msg) __attribute__((hot));
void		ft_try_actions(t_philo *philo, void (*actions)(t_philo *philo)) \
							__attribute__((hot));
void		ft_wait(int time) __attribute__((hot));
void		ft_finish(t_philo *philo, t_philo_state state);

void		ft_kill_threads(t_table *table);
#endif
