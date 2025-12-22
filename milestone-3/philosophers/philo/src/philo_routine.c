/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 12:03:26 by amarquez          #+#    #+#             */
/*   Updated: 2025/11/24 12:03:27 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

void	print_routine(t_philo *philo, int routine)
{
	size_t	time;
	size_t	curr_time;

	pthread_mutex_lock(philo->print_mutex);
	if (did_anyone_die(philo->table) && routine != DIED)
	{
		pthread_mutex_unlock(philo->print_mutex);
		return ;
	}
	time = philo->start_time;
	curr_time = get_current_time();
	if (routine == TAKING_FORK)
		printf(YELLOW"[%zu] %d has taken a fork\n"NC, curr_time - time,
			philo->id);
	else if (routine == EATING)
		printf(GREEN"[%zu] %d is eating\n"NC, curr_time - time, philo->id);
	else if (routine == SLEEPING)
		printf(PURPLE"[%zu] %d is sleeping\n"NC, curr_time - time, philo->id);
	else if (routine == THINKING)
		printf(CYAN"[%zu] %d is thinking\n"NC, curr_time - time, philo->id);
	else if (routine == DIED)
		printf(RED"[%zu] %d has died\n"NC, curr_time - time, philo->id);
	pthread_mutex_unlock(philo->print_mutex);
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_routine(philo, TAKING_FORK);
	if (philo->left_fork != philo->right_fork)
	{
		pthread_mutex_lock(philo->right_fork);
		print_routine(philo, TAKING_FORK);
		pthread_mutex_lock(&philo->meal_mutex);
		philo->meals_eaten++;
		philo->last_meal_time = get_current_time();
		pthread_mutex_unlock(&philo->meal_mutex);
		print_routine(philo, EATING);
		ft_usleep((size_t)philo->time_to_eat);
		pthread_mutex_unlock(philo->right_fork);
	}
	else
		ft_usleep(philo->time_to_die);
	pthread_mutex_unlock(philo->left_fork);
}

void	philo_think(t_philo *philo)
{
	if (did_anyone_die(philo->table))
		return ;
	print_routine(philo, THINKING);
}

void	philo_sleep(t_philo *philo)
{
	if (did_anyone_die(philo->table))
		return ;
	print_routine(philo, SLEEPING);
	ft_usleep(philo->time_to_sleep);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(50);
	while (!did_anyone_die(philo->table))
	{
		philo_eat(philo);
		philo_think(philo);
		philo_sleep(philo);
	}
	return (NULL);
}
