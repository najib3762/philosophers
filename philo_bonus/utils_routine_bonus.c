/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_routine_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:29:47 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:48 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	put_time_memset(long long *last_meal)
{
	long long	current_time;
	int			i;

	i = 0;
	current_time = get_current_time();
	memset(last_meal, 0, sizeof(long long));
	while (i < 8)
	{
		memset(((unsigned char *)last_meal) + i, \
		((unsigned char *)&current_time)[i], 1);
		i++;
	}
}

int	eating(t_programme *prog, int i)
{
	sem_wait(prog->sem_id);
	philo_print(prog, i, FORK);
	sem_wait(prog->sem_id);
	philo_print(prog, i, FORK);
	philo_print(prog, i, EATING);
	ft_usleep(prog->time_to_eat);
	put_time_memset(&prog->time_philo_dead);
	sem_post(prog->sem_id);
	sem_post(prog->sem_id);
	prog->num_ate++;
	return (0);
}

int	sleeping(t_programme *prog, int i)
{
	philo_print(prog, i, SLEEPING);
	ft_usleep(prog->time_to_sleep);
	return (0);
}

int	thinking(t_programme *prog, int i)
{
	philo_print(prog, i, THINKING);
	return (0);
}

int	philo_print(t_programme *prog, int id, char *status)
{
	long long	time;

	time = new_time(prog->time0);
	printf("%lld %d %s \n", time, id, status);
	return (0);
}
