/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:16:42 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/14 21:16:43 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(t_programme *prog)
{
	prog->time0 = get_current_time();
	printf("%lld 1 %s \n", (get_current_time() - prog->time0), FORK);
	ft_usleep(prog->input.time_to_die);
	printf("%lld 1 %s\n", (get_current_time() - prog->time0), DIED);
	return (-1);
}

int	main(int ac, char **av)
{
	t_programme	pt;

	if (ac == 5 || ac == 6)
	{
		if (check_errors(&pt, av, ac) != 0 || forks_init(&pt)
			|| philo_init(&pt))
		{
			print_error("Error\n");
			return (1);
		}
		if (pt.input.nbr_philo == 1)
		{
			if (one_philo(&pt))
			{
				ft_free(&pt);
				return (1);
			}
		}
		if (create_threads(&pt))
			return (1);
		ft_free(&pt);
	}
	else
		print_error("Error\n");
	return (0);
}
