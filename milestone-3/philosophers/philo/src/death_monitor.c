/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 13:06:34 by amarquez          #+#    #+#             */
/*   Updated: 2025/11/27 13:06:36 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

static void	finished_eating_check(t_table *table, int i, int *full_meals)
{
	if (table->philos[i].meals_eaten >= table->num_times_to_eat)
		(*full_meals)++;
}

void	someone_died(t_table *table)
{
	pthread_mutex_lock(&table->death_mutex);
	table->is_anyone_dead = 1;
	pthread_mutex_unlock(&table->death_mutex);
}

int	did_anyone_die(t_table *table)
{
	int	dead;

	pthread_mutex_lock(&table->death_mutex);
	dead = table->is_anyone_dead;
	pthread_mutex_unlock(&table->death_mutex);
	return (dead);
}

static int	check_philo_status(t_table *table, int i, int *full_meals)
{
	size_t	time_since_meal;

	pthread_mutex_lock(&table->philos[i].meal_mutex);
	time_since_meal = get_current_time() - table->philos[i].last_meal_time;
	if (time_since_meal >= (size_t)table->philos[i].time_to_die)
	{
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
		someone_died(table);
		print_routine(&table->philos[i], DIED);
		return (1);
	}
	if (table->num_times_to_eat)
		finished_eating_check(table, i, full_meals);
	pthread_mutex_unlock(&table->philos[i].meal_mutex);
	return (0);
}

void	monitor_deaths(t_table *table)
{
	int		i;
	int		full_meals;

	while (!did_anyone_die(table))
	{
		i = 0;
		full_meals = 0;
		while (i < table->num_philos)
		{
			if (check_philo_status(table, i, &full_meals))
				return ;
			i++;
		}
		if (full_meals == table->num_philos)
			someone_died(table);
	}
}
