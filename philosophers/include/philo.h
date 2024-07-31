/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mancorte <mancorte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 20:23:11 by mancorte          #+#    #+#             */
/*   Updated: 2024/07/31 20:23:33 by mancorte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <inttypes.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2
# define PTHREAD_ERROR 3

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}					t_state;

struct	s_data;

/**
 * @brief La estructura 't_philo' representa a un filósofo en
 * el problema de los filósofos comensales.
 *
 * @param id El identificador único del filósofo.
 * @param nb_meals_had El número de comidas que ha tenido el filósofo.
 * @param data Un puntero a la estructura de datos compartida.
 * @param state El estado actual del filósofo (por ejemplo, pensando,
 * 				comiendo, durmiendo).
 * @param left_f Un puntero al mutex del tenedor izquierdo del filósofo.
 * @param right_f Un puntero al mutex del tenedor derecho del filósofo.
 * @param mut_state Un mutex para cambiar el estado del filósofo de forma
 * segura.
 * @param mut_nb_meals_had Un mutex para cambiar el número de comidas
 *  que ha tenido el filósofo de forma segura.
 * @param mut_last_eat_time Un mutex para cambiar la última
 * vez que el filósofo comió de forma segura.
 * @param last_eat_time La última vez que el filósofo comió.
 */
typedef struct s_philo
{
	int				id;
	int				color;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	u_int64_t		last_eat_time;
}					t_philo;

/**
 * @brief La estructura 't_data' representa los datos compartidos entre todos
 * los filósofos.
 *
 * @param nb_philos El número total de filósofos.
 * @param nb_meals El número total de comidas que deben tener los filósofos.

 * @param nb_full_p El número de filósofos que están llenos (han comido el número
 * 				requerido de comidas).
 * @param keep_iterating Un booleano para determinar si los filósofos deben
 * 				seguir iterando.
 * @param eat_time El tiempo que un filósofo pasa comiendo.
 * @param die_time El tiempo que un filósofo puede pasar sin comer antes de
 * 				morir.
 * @param sleep_time El tiempo que un filósofo pasa durmiendo.
 * @param start_time El tiempo en el que comenzó la simulación.
 * @param mut_eat_t Un mutex para cambiar el tiempo de comer de forma segura.
 * @param mut_die_t Un mutex para cambiar el tiempo de morir de forma segura.
 * @param mut_sleep_t Un mutex para cambiar el tiempo de dormir de forma segura.
 * @param mut_print Un mutex para imprimir de forma segura.

	* @param mut_nb_philos Un mutex para cambiar el número de filósofos de forma segura.

	* @param mut_keep_iter Un mutex para cambiar el booleano 'keep_iterating' de forma segura.

	* @param mut_start_time Un mutex para cambiar el tiempo de inicio de forma segura.

	* @param check_all_alive Un hilo para checkorear si todos los filósofos están vivos.

	* @param check_all_full Un hilo para checkorear si todos los filósofos están llenos.
 * @param philo_ths Un array de hilos, cada uno representando a un filósofo.
 * @param forks Un array de mutex, cada uno representando a un tenedor.
 * @param philos Un array de 't_philo', cada uno representando a un filósofo.
 */
typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	bool			keep_iterating;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	mut_eat_t;
	pthread_mutex_t	mut_die_t;
	pthread_mutex_t	mut_sleep_t;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_nb_philos;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	mut_start_time;
	pthread_t		check_all_alive;
	pthread_t		check_all_full;
	pthread_t		*philo_ths;
	pthread_mutex_t	*forks;
	t_philo			*philos;
}					t_data;

// init_data.c
int					init_data(t_data *data, int argc, char **argv);
int					malloc_data(t_data *data);
int					init_philos(t_data *data);
int					init_forks(t_data *data);

// parse.c
int					check_input(int argc, char **argv);
int					ft_atoi(char *str);
void				print_instruction(void);
int					wrong_input_check(int argc, char **argv);
int					is_input_digit(int argc, char **argv);

// time.c
uint64_t			get_time(void);
uint64_t			get_die_time(t_data *data);
uint64_t			get_sleep_time(t_data *data);
uint64_t			get_start_time(t_data *data);
uint64_t			get_last_eat_time(t_philo *philo);

// eat.c
void				update_last_meal_time(t_philo *philo);
int					eat(t_philo *philo);

// take_fork.c
int					take_forks(t_philo *philo);
int					take_left_fork(t_philo *philo);
int					take_right_fork(t_philo *philo);

// drop_fork.c
void				drop_forks(t_philo *philo);
void				drop_left_fork(t_philo *philo);
void				drop_right_fork(t_philo *philo);

// sleep.c
void				ft_usleep(uint64_t sleep_time);
void				sleep_for_eating(t_philo *philo);
int					ft_sleep(t_philo *philo);

// think.c
int					think(t_philo *philo);

// philo_n_meal_f.c
int					handle_1_philo(t_philo *philo);
bool				nb_meals_option(t_data *data);

// getters.c
uint64_t			get_eat_time(t_data *data);
int					get_nb_philos(t_data *data);
int					get_nb_meals_philo_had(t_philo *philo);
t_state				get_philo_state(t_philo *philo);
bool				get_keep_iter(t_data *data);

// setters.c
void				set_keep_iterating(t_data *data, bool set_to);
void				set_philo_state(t_philo *philo, t_state state);

// setter.c
void				set_philo_state(t_philo *philo, t_state state);
void				set_keep_iterating(t_data *data, bool set_to);

// routine.c
void				*routine(void *philo_p);

// checker.c
bool				check_philo_died(t_philo *philo);
void				*all_alive_routine(void *data_p);
void				*all_full_routine(void *data_p);
void				notify_all_philos(t_data *data);
bool				is_philo_full(t_data *data, t_philo *philo);

// print.c
void				print_msg(int color, t_data *data, int id, char *msg);
void				print_mut(t_data *data, char *msg);

// error.c
int					print_error(char *msg, int ERROR_);

// free.c
void				free_data(t_data *data);

#endif