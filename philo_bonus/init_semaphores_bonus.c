/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_semaphores.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:52:17 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 18:52:18 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	open_semaphore(sem_t **sem, const char *name, int value)
{
	*sem = sem_open(name, O_CREAT | O_EXCL, 0666, value);
	if (*sem == SEM_FAILED)
	{
		print_error("Error \n");
		exit(1);
	}
}

void	init_semaphores(t_programme *prog, int **pids)
{
	*pids = malloc(sizeof(int) * prog->nbr_philo);
	if (!*pids)
	{
		print_error("Error\n");
		exit(1);
	}
	sem_unlink("/sem_id");
	sem_unlink("/sem_kill");
	open_semaphore(&prog->sem_id, "/sem_id", prog->nbr_philo);
	open_semaphore(&prog->sem_kill, "/sem_kill", 1);
}

// int	is_eat(t_programme *prog)
// {
// 	int	res;

// 	res = 0;
// 	sem_wait(prog->sem_eat);
// 	if (prog->nbr_limit_meals > prog->num_ate)
// 		res = 1;
// 	sem_post(prog->sem_eat);
// 	return (res);
// }
