/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:16:03 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/14 21:16:04 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	join_threads(t_programme *prog);

int	create_threads(t_programme *prog)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&prog->dead);
	prog->philo_dead = 0;
	pthread_mutex_unlock(&prog->dead);
	prog->time0 = get_current_time();
	while (i < prog->input.nbr_philo)
	{
		pthread_mutex_lock(&prog->id_thread);
		prog->nbr_thread = i;
		pthread_mutex_unlock(&prog->id_thread);
		if (pthread_create(&prog->philo[i].thread, NULL, &routine, prog) != 0)
		{
			return (-1);
		}
		usleep(20);
		i++;
	}
	if (pthread_create(&prog->messs2ol, NULL, &checker, prog) != 0)
		return (-1);
	if (join_threads(prog))
		return (-1);
	return (0);
}

static int	join_threads(t_programme *prog)
{
	int	j;

	j = 0;
	while (j < prog->input.nbr_philo)
	{
		if (pthread_join(prog->philo[j].thread, NULL) != 0)
			return (-1);
		j++;
	}
	if (pthread_join(prog->messs2ol, NULL) != 0)
		return (-1);
	return (0);
}

void	unlock_forks(t_programme *prog, int i)
{
	pthread_mutex_unlock(&prog->keteb);
	pthread_mutex_unlock(&prog->forks[prog->philo[i].fork.l_fork]);
	pthread_mutex_unlock(&prog->forks[prog->philo[i].fork.r_fork]);
	usleep(5);
	pthread_mutex_destroy(&prog->forks[prog->philo[i].fork.l_fork]);
	pthread_mutex_destroy(&prog->forks[prog->philo[i].fork.r_fork]);
	pthread_mutex_destroy(&prog->keteb);
}

// int	destroy_forks(t_programme *prog)
// {
// 	int	i;

// 	i = 0;
// 	while (i < prog->input.nbr_philo)
// 	{
// 		pthread_mutex_destroy(&prog->forks[i]);
// 		i++;
// 	}
// 		pthread_mutex_destroy(&prog->forks[prog->philo[i].fork.l_fork]);
// 	pthread_mutex_destroy(&prog->forks[prog->philo[i].fork.r_fork]);
// 	pthread_mutex_destroy(&prog->keteb);
// 	return (0);
// }
