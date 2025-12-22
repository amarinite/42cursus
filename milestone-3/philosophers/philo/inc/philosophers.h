/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:11:08 by amarquez          #+#    #+#             */
/*   Updated: 2025/11/24 12:11:09 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# define EXIT_ERROR 1
# define EXIT_SUCCESS 0
# define SUCCESS 1
# define FAILURE 0

# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <sys/time.h>

# define NC		"\e[0m"
# define RED	"\e[31m"
# define GREEN	"\e[32m"
# define YELLOW	"\e[33m"
# define PURPLE	"\e[35m"
# define CYAN	"\e[36m"

typedef enum e_routine
{
	DIED = 0,
	EATING = 1,
	SLEEPING = 2,
	THINKING = 3,
	TAKING_FORK = 4,
}	t_routine;

typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_eaten;
	size_t			last_meal_time;
	int				is_dead;
	size_t			start_time;
	struct s_table	*table;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
}	t_philo;

typedef struct s_table
{
	t_philo			*philos;
	pthread_mutex_t	*forks;
	int				num_philos;
	int				is_anyone_dead;
	int				num_times_to_eat;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	print_mutex;
}	t_table;

/***** PHILOSOPHERS *****/
int		clean_table(t_table *table);

/***** NUM_UTILS *****/
int		is_valid_positive_int(const char *str);
int		ft_atoi(char *str);

/***** TIME_UTILS *****/
size_t	get_current_time(void);
int		ft_usleep(size_t milliseconds);

/***** INIT_ALL *****/
int		init_all(char **argv, t_table *table);

/***** PHILO_ROUTINE *****/
void	*philo_routine(void *arg);
void	print_routine(t_philo *philo, int routine);

/***** DEATH_MONITOR *****/
void	monitor_deaths(t_table *table);
int		did_anyone_die(t_table *table);

#endif

// typedef struct s_fork
// {
// 	int				fork_id;
// 	pthread_mutex_t	fork_mutex;
// }	t_fork;
