/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   odd_even.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 15:56:03 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/14 21:16:51 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_unlock(t_programme *prog, int i);

int	odd_philo(t_programme *prog, int i)
{
	usleep(50);
	if (pthread_mutex_lock(&prog->forks[prog->philo[i].fork.l_fork]) != 0)
		return (-1);
	if (print_philo(prog, prog->philo[i].id, FORK))
		return (-1);
	if (pthread_mutex_lock(&prog->forks[prog->philo[i].fork.r_fork]) != 0)
		return (-1);
	if (print_philo(prog, prog->philo[i].id, FORK))
		return (-1);
	if (print_philo(prog, prog->philo[i].id, EATING))
		return (-1);
	if (prog->input.time_to_eat > prog->input.time_to_die)
		ft_usleep(prog->input.time_to_die);
	else
		ft_usleep(prog->input.time_to_eat);
	pthread_mutex_lock(&prog->is_time);
	prog->philo[i].time_to_die = get_current_time();
	pthread_mutex_unlock(&prog->is_time);
	ft_unlock(prog, i);
	return (0);
}

int	even_philo(t_programme *prog, int i)
{
	if (pthread_mutex_lock(&prog->forks[prog->philo[i].fork.r_fork]) != 0)
		return (-1);
	if (print_philo(prog, prog->philo[i].id, FORK))
		return (-1);
	if (pthread_mutex_lock(&prog->forks[prog->philo[i].fork.l_fork]) != 0)
		return (-1);
	if (print_philo(prog, prog->philo[i].id, FORK))
		return (-1);
	if (print_philo(prog, prog->philo[i].id, EATING))
		return (-1);
	if (prog->input.time_to_eat > prog->input.time_to_die)
		ft_usleep(prog->input.time_to_die);
	else
		ft_usleep(prog->input.time_to_eat);
	pthread_mutex_lock(&prog->is_time);
	prog->philo[i].time_to_die = get_current_time();
	pthread_mutex_unlock(&prog->is_time);
	ft_unlock(prog, i);
	return (0);
}

static int	ft_unlock(t_programme *prog, int i)
{
	if (pthread_mutex_unlock(&prog->forks[prog->philo[i].fork.l_fork]) != 0)
		return (-1);
	if (pthread_mutex_unlock(&prog->forks[prog->philo[i].fork.r_fork]) != 0)
		return (-1);
	pthread_mutex_lock(&prog->race);
	prog->philo[i].num_ate++;
	pthread_mutex_unlock(&prog->race);
	return (0);
}
