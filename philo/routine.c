/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:17:27 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/18 13:40:28 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_programme	*prog;
	int			i;

	prog = (t_programme *)arg;
	pthread_mutex_lock(&prog->id_thread);
	i = prog->nbr_thread;
	pthread_mutex_unlock(&prog->id_thread);
	if (prog->input.nbr_limit_meals > 0)
	{
		while (is_full(prog, i) == 1 && philo_dead(prog))
			do_routine(prog, i);
	}
	else
	{
		while (philo_dead(prog))
		{
			if (do_routine(prog, i))
			{
				break ;
			}
		}
	}
	return (NULL);
}

int	do_routine(t_programme *prog, int i)
{
	if (prog->philo[i].id % 2 == 0)
		even_philo(prog, i);
	else
		odd_philo(prog, i);
	if (is_full2(prog, i) == 1)
	{
		if (ft_sleeping(prog, i))
			return (-1);
		if (ft_thinking(prog, i))
			return (-1);
	}
	return (0);
}

void	*checker(void *arg)
{
	t_programme	*prog;
	int			i;

	prog = (t_programme *)arg;
	i = 0;
	if (prog->input.nbr_limit_meals > 0)
	{
		while (is_full(prog, i) == 1 && philo_dead(prog))
			is_dead(prog, &i);
	}
	else
	{
		while (philo_dead(prog))
		{
			if (is_dead(prog, &i))
				break ;
			usleep(200);
		}
	}
	return (NULL);
}

int	is_dead(t_programme *prog, int *i)
{
	long long	time;

	if (*i == prog->input.nbr_philo - 1)
		*i = 0;
	pthread_mutex_lock(&prog->is_time);
	time = new_time(prog->philo[*i].time_to_die);
	pthread_mutex_unlock(&prog->is_time);
	if (time > prog->input.time_to_die)
	{
		print_philo(prog, prog->philo[*i].id, DIED);
		pthread_mutex_lock(&prog->dead);
		prog->philo_dead = 1;
		pthread_mutex_unlock(&prog->dead);
		return (-1);
	}
	(*i)++;
	return (0);
}
