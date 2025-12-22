/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarquez <amarquez@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 12:26:10 by amarquez          #+#    #+#             */
/*   Updated: 2025/11/17 12:26:11 by amarquez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/philosophers.h"

int	validate_args(int argc, char **argv)
{
	int	i;

	if (argc != 5 && argc != 6)
		return (FAILURE);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_positive_int(argv[i]))
			return (FAILURE);
		i++;
	}
	i = 1;
	while (i < 5)
	{
		if (ft_atoi(argv[i]) < 1)
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}

int	clean_table(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->num_philos)
	{
		if (pthread_join(table->philos[i].thread, NULL) != 0)
			return (FAILURE);
		i++;
	}
	i = 0;
	while (i < table->num_philos)
	{
		pthread_mutex_destroy(&table->forks[i]);
		pthread_mutex_destroy(&table->philos[i].meal_mutex);
		i++;
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->death_mutex);
	free(table->philos);
	free(table->forks);
	return (SUCCESS);
}

int	main(int argc, char **argv)
{
	t_table	table;

	if (!validate_args(argc, argv))
		return (printf("Invalid args\n"), EXIT_ERROR);
	table.is_anyone_dead = 0;
	table.num_philos = ft_atoi(argv[1]);
	if (!init_all(argv, &table))
		return (printf("Malloc failure\n"), EXIT_ERROR);
	monitor_deaths(&table);
	if (!clean_table(&table))
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}
