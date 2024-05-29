/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:29:17 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:19 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <fcntl.h>
# include <limits.h>
# include <pthread.h>
# include <semaphore.h>
# include <signal.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

# define FORK " has taken a fork"
# define EATING " is eating"
# define SLEEPING " is sleeping"
# define THINKING " is thinking"
# define DIED " is died"

typedef struct s_programme
{
	int			id;
	int			num_ate;
	long long	time_philo_dead;
	pthread_t	thread;
	long long	time0;
	sem_t		*sem_id;
	sem_t		*sem_kill;
	long		nbr_philo;
	long		time_to_eat;
	long		time_to_sleep;
	long		time_to_die;
	long		nbr_limit_meals;
}				t_programme;

int				check_errors(t_programme *data, char **av, int ac);
long long		ft_atoi(char *str);
int				ft_strlen(char *str);
int				is_digit(char *c);
void			print_error(char *str);
long long		new_time(long long time);
size_t			get_current_time(void);
int				ft_usleep(size_t time);
int				eating(t_programme *prog, int i);
int				sleeping(t_programme *prog, int i);
int				thinking(t_programme *prog, int i);
int				philo_print(t_programme *prog, int id, char *status);
void			print_error(char *str);
int				philo_create(t_programme *prog, int **pids);
void			init_semaphores(t_programme *prog, int **pids);
int				is_eat(t_programme *prog);
void			free_tab(char **tab);
char			**ft_split(const char *s, char c);
#endif
