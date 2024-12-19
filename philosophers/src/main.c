/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 19:47:01 by mancorte          #+#    #+#             */
/*   Updated: 2024/08/16 19:54:14 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int join_threads(t_data *data)
{
    int i;
    int nb_philos;

    nb_philos = get_nb_philos(data);
    i = -1;
    if (pthread_join(data->check_all_alive, NULL))
        return (1);
    if (nb_meals_option(data) == true && pthread_join(data->check_all_full, NULL))
        return (1);
    while (++i < nb_philos)
    {
        if (data->philo_ths[i] != 0)
        {
            if (pthread_join(data->philo_ths[i], NULL))
                return (1);
        }
    }
    return (0);
}


int run_threads(t_data *data)
{
    int i;
    int num_philos;

    i = 0;
    num_philos = get_nb_philos(data);
    data->start_time = get_time();

    while (i < num_philos)
    {
        if (pthread_create(&data->philo_ths[i], NULL, &routine, &data->philos[i]) != 0)
        {
            return (print_error("Error creating threads", PTHREAD_ERROR));
        }
        i++;
    }
    if (pthread_create(&data->check_all_alive, NULL, &all_alive_routine, data))
        return (1);
    if (nb_meals_option(data) == true && pthread_create(&data->check_all_full, NULL, &all_full_routine, data))
        return (1);
    return (0);
}

int	philosophers(int argc, char **argv)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (data == NULL)
		return (MALLOC_ERROR);
	if (init_data(data, argc, argv) != 0)
		return (MALLOC_ERROR);
	init_philos(data);
	init_forks(data);
	printf("\n\e[4mSTARTING THE SHOW\e[0m:\n\n");
	run_threads(data);
	join_threads(data);
	free_data(data);
	return (0);
}

int	main(int argc, char **argv)
{
	if (check_input(argc, argv) != 0)
	{
		print_instruction();
		return (print_error("Try to introduce the correct input", WRONG_INPUT));
	}
	if (philosophers(argc, argv) != 0)
		return (print_error("Malloc allocation has an error", MALLOC_ERROR));
	return (0);
}
