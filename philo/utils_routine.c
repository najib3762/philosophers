/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:17:38 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/14 21:17:39 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_sleeping(t_programme *prog, int i)
{
	if (print_philo(prog, prog->philo[i].id, SLEEPING))
		return (-1);
	if (prog->input.time_to_sleep > prog->input.time_to_die)
		ft_usleep(prog->input.time_to_die);
	else
		ft_usleep(prog->input.time_to_sleep);
	return (0);
}

int	ft_thinking(t_programme *prog, int i)
{
	if (print_philo(prog, prog->philo[i].id, THINKING))
		return (-1);
	return (0);
}

int	print_philo(t_programme *prog, int i, char *status)
{
	if (philo_dead(prog) == 0)
		return (-1);
	pthread_mutex_lock(&prog->keteb);
	if (philo_dead(prog) == 0)
	{
		unlock_forks(prog, i);
		return (-1);
	}
	else
		printf("%lld %d %s \n", (get_current_time() - prog->time0), i, status);
	pthread_mutex_unlock(&prog->keteb);
	return (0);
}

int	philo_dead(t_programme *prog)
{
	int	res;

	res = 0;
	pthread_mutex_lock(&prog->dead);
	if (prog->philo_dead == 0)
		res = 1;
	pthread_mutex_unlock(&prog->dead);
	return (res);
}
