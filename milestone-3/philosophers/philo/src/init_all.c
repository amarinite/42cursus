/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 15:31:34 by amarquez          #+#    #+#             */
/*   Updated: 2025/11/25 15:31:36 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	init_table(t_table *table, char **argv)
{
	int	i;

	pthread_mutex_init(&table->print_mutex, NULL);
	pthread_mutex_init(&table->death_mutex, NULL);
	table->philos = malloc(table->num_philos * sizeof(t_philo));
	table->is_anyone_dead = 0;
	if (!table->philos)
		return (FAILURE);
	table->forks = malloc(table->num_philos * sizeof(pthread_mutex_t));
	if (!table->forks)
		return (FAILURE);
	i = 0;
	if (argv[5])
		table->num_times_to_eat = ft_atoi(argv[5]);
	else
		table->num_times_to_eat = 0;
	return (SUCCESS);
}

void	assign_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		table->philos[i].right_fork = &table->forks[i];
		table->philos[i].left_fork = &table->forks[(i + 1) % table->num_philos];
		i++;
	}
}

void	init_philos(t_table *table, char **argv)
{
	int			i;
	size_t		time;

	i = 0;
	time = get_current_time();
	while (i < table->num_philos)
	{
		table->philos[i].time_to_die = ft_atoi(argv[2]);
		table->philos[i].time_to_eat = ft_atoi(argv[3]);
		table->philos[i].time_to_sleep = ft_atoi(argv[4]);
		table->philos[i].is_dead = 0;
		table->philos[i].last_meal_time = time;
		pthread_mutex_init(&table->philos[i].meal_mutex, NULL);
		table->philos[i].start_time = time;
		table->philos[i].meals_eaten = 0;
		table->philos[i].id = i + 1;
		table->philos[i].print_mutex = &table->print_mutex;
		table->philos[i].table = table;
		pthread_mutex_init(&table->forks[i], NULL);
		i++;
	}
	assign_forks(table);
}

int	init_all(char **argv, t_table *table)
{
	t_philo		*philos;
	int			i;

	philos = NULL;
	if (!init_table(table, argv))
		return (FAILURE);
	philos = table->philos;
	init_philos(table, argv);
	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_create(&table->philos[i].thread, NULL,
				&philo_routine, &table->philos[i]) != 0)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
