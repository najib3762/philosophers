/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:17:19 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/14 21:17:20 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef pthread_mutex_t	t_mutex;
typedef struct s_philo	t_philo;

# define FORK " has taken a fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"
# define DIED " is died"

typedef struct s_forks
{
	int					r_fork;
	int					l_fork;

}						t_forks;

typedef struct s_data
{
	long				nbr_philo;
	long				time_to_eat;
	long				time_to_sleep;
	long				time_to_die;
	long				nbr_limit_meals;
}						t_data;
typedef struct s_philo
{
	int					id;
	t_forks				fork;
	pthread_t			thread;
	long long			time_to_die;
	int					num_ate;
}						t_philo;
typedef struct s_programme
{
	int					nbr_thread;
	int					philo_dead;
	long long			time0;
	t_data				input;
	pthread_t			messs2ol;
	t_philo				*philo;
	t_mutex				*forks;
	t_mutex				keteb;
	t_mutex				race;
	t_mutex				id_thread;
	t_mutex				dead;
	t_mutex				is_time;
	t_mutex				check_dead;
}						t_programme;

int						create_threads(t_programme *prog);
void					print_error(char *str);
void					init_input(t_programme *prog);
void					ft_bzero(void *s, size_t n);
int						check_errors(t_programme *data, char **av, int ac);
// void					parsing_data(t_programme *prog, char **av);
void					parsing_data(t_programme *prog, char **av, int ac);
void					ft_free(t_programme *prog);
int						forks_init(t_programme *prog);
size_t					get_current_time(void);
int						ft_usleep(size_t time);
int						philo_init(t_programme *prog);
void					*routine(void *arg);
int						do_routine(t_programme *prog, int i);
void					*checker(void *arg);
int						is_dead(t_programme *prog, int *i);
int						ft_sleeping(t_programme *prog, int i);
int						ft_thinking(t_programme *prog, int i);
long long				ft_atoi(char *str);
int						ft_strlen(char *str);
int						is_digit(char *c);
long long				new_time(long long time);
int						print_philo(t_programme *prog, int i, char *status);
void					unlock_forks(t_programme *prog, int i);
int						is_full(t_programme *prog, int i);
int						philo_dead(t_programme *prog);
int						odd_philo(t_programme *prog, int i);
int						even_philo(t_programme *prog, int i);
int						is_full2(t_programme *prog, int i);
char					**ft_split(const char *s, char c);

#endif
