/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:28:58 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 18:29:00 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	one_philo(t_programme *prog)
{
	prog->time0 = get_current_time();
	printf("%lld 1 %s \n", (get_current_time() - prog->time0), FORK);
	ft_usleep(prog->time_to_die);
	printf("%lld 1 %s\n", (get_current_time() - prog->time0), DIED);
	return (-1);
}

void	kill_all(t_programme *prog, int *pids)
{
	int	i;

	i = 0;
	sem_close(prog->sem_id);
	sem_close(prog->sem_kill);
	while (i < prog->nbr_philo)
	{
		kill(pids[i], SIGKILL);
		i++;
	}
}

void	waitclean(t_programme *prog, int *pids)
{
	int	stat;
	int	i;

	stat = 0;
	i = 0;
	while (i < prog->nbr_philo)
	{
		waitpid(-1, &stat, 0);
		if (WIFEXITED(stat) && WEXITSTATUS(stat) != EXIT_SUCCESS)
			kill_all(prog, pids);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_programme	prog;
	int			*pids;

	pids = NULL;
	if (ac == 5 || ac == 6)
	{
		if (check_errors(&prog, av, ac) != 0)
		{
			print_error("Error\n");
			return (1);
		}
		if (prog.nbr_philo == 1)
		{
			if (one_philo(&prog))
				return (1);
		}
		init_semaphores(&prog, &pids);
		philo_create(&prog, &pids);
	}
	waitclean(&prog, pids);
	free(pids);
	return (0);
}
