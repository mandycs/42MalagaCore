/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 19:51:17 by mancorte          #+#    #+#             */
/*   Updated: 2024/07/31 20:22:17 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	init_forks(t_data *data)
{
	int		i;
	t_philo	*philos;

	i = -1;
	philos = data->philos;
	printf("\n\e[4mFORKS INITIALIZATION\e[0m:\n\n");
	sleep(1);
	while (++i < data->nb_philos)
	{
		pthread_mutex_init(&data->forks[i], NULL);
		printf("\033[0;%dmFork[%i] initialized!\033[0m\n",
			philos[i].color, i + 1);
	}
	i = 0;
	philos[i].left_f = &data->forks[i];
	philos[i].right_f = &data->forks[data->nb_philos - 1];
	printf("\n");
	while (++i < data->nb_philos)
	{
		philos[i].left_f = &data->forks[i];
		philos[i].right_f = &data->forks[i - 1];
	}
	return (0);
}

int	init_philos(t_data *data)
{
	t_philo	*philos;
	int		i;

	i = -1;
	philos = data->philos;
	printf("\n\e[4mPHILOSOPHERS INITIALIZATION\e[0m:\n\n");
	sleep(1);
	while (++i < data->nb_philos)
	{
		philos[i].data = data;
		philos[i].id = i + 1;
		philos[i].color = 30 + (i % 8);
		philos[i].nb_meals_had = 0;
		philos[i].state = IDLE;
		pthread_mutex_init(&philos[i].mut_state, NULL);
		pthread_mutex_init(&philos[i].mut_nb_meals_had, NULL);
		pthread_mutex_init(&philos[i].mut_last_eat_time, NULL);
		update_last_meal_time(&philos[i]);
		printf("\033[0;%dmPhilo[%i] initialized!\n\033[0m",
			philos[i].color, philos[i].id);
	}
	sleep(1);
	return (0);
}

int	malloc_data(t_data *data)
{
	data->philos = malloc(sizeof(t_philo) * data->nb_philos);
	if (data->philos == NULL)
	{
		free(data);
		return (MALLOC_ERROR);
	}
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (data->forks == NULL)
	{
		free(data->philos);
		return (MALLOC_ERROR);
	}
	data->philo_ths = malloc(sizeof(pthread_t) * data->nb_philos);
	if (data->philo_ths == NULL)
	{
		free(data->philos);
		free(data->forks);
		return (MALLOC_ERROR);
	}
	return (0);
}

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_full_p = 0;
	data->keep_iterating = true;
	data->nb_philos = ft_atoi(argv[1]);
	data->die_time = (u_int64_t)ft_atoi(argv[2]);
	data->eat_time = (u_int64_t)ft_atoi(argv[3]);
	data->sleep_time = (u_int64_t)ft_atoi(argv[4]);
	data->nb_meals = -1;
	if (argc == 6)
		data->nb_meals = ft_atoi(argv[5]);
	pthread_mutex_init(&data->mut_eat_t, NULL);
	pthread_mutex_init(&data->mut_sleep_t, NULL);
	pthread_mutex_init(&data->mut_die_t, NULL);
	pthread_mutex_init(&data->mut_print, NULL);
	pthread_mutex_init(&data->mut_nb_philos, NULL);
	pthread_mutex_init(&data->mut_keep_iter, NULL);
	pthread_mutex_init(&data->mut_start_time, NULL);
	printf("\e[45mData initialized!\033[;0m\n\n");
	sleep(1);
	return (malloc_data(data));
}
