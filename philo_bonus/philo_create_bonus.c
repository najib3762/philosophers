/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:29:33 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:34 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	is_dead(t_programme *prog, int id);

void	*checker(void *args)
{
	t_programme	*prog;
	int			i;

	prog = (t_programme *)args;
	i = prog->id;
	while (1)
	{
		is_dead(prog, i);
		usleep(100);
	}
	return (NULL);
}

static void	is_dead(t_programme *prog, int id)
{
	long long	time;

	time = new_time(prog->time_philo_dead);
	if (time > prog->time_to_die)
	{
		sem_wait(prog->sem_kill);
		printf("%lld %d %s \n", (get_current_time() - prog->time_philo_dead), \
		id, DIED);
		exit(1);
	}
}

int	do_routine(t_programme *prog, int i)
{
	eating(prog, i);
	sleeping(prog, i);
	thinking(prog, i);
	return (0);
}

int	routine(t_programme *prog, int i)
{
	prog->id = i;
	prog->time_philo_dead = 0;
	pthread_create(&prog->thread, NULL, &checker, (void *)prog);
	if (prog->nbr_limit_meals > 0)
	{
		while (prog->nbr_limit_meals > prog->num_ate)
			do_routine(prog, i);
	}
	else
	{
		while (1)
			do_routine(prog, i);
	}
	return (0);
}

int	philo_create(t_programme *prog, int **pids)
{
	pid_t	pid_fork;
	int		i;

	i = 0;
	while (i < prog->nbr_philo)
	{
		pid_fork = fork();
		if (pid_fork < 0)
		{
			print_error("Error\n");
			free(pids);
			exit(1);
		}
		if (pid_fork == 0)
		{
			routine(prog, i + 1);
			exit(0);
		}
		else
		{
			(*pids)[i] = pid_fork;
		}
		i++;
	}
	return (0);
}
