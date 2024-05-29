/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 15:12:48 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 15:12:50 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_input(t_programme *prog)
{
	prog->input.nbr_philo = 0;
	prog->input.time_to_die = 0;
	prog->input.time_to_eat = 0;
	prog->input.time_to_sleep = 0;
	prog->input.nbr_limit_meals = 0;
}

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	ptr = s;
	while (n)
	{
		*ptr = 0;
		ptr++;
		n--;
	}
}

void	parsing_data(t_programme *prog, char **av, int ac)
{
	init_input(prog);
	prog->input.nbr_philo = ft_atoi(av[1]);
	prog->input.time_to_die = ft_atoi(av[2]);
	prog->input.time_to_eat = ft_atoi(av[3]);
	prog->input.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		prog->input.nbr_limit_meals = ft_atoi(av[5]);
	else
		prog->input.nbr_limit_meals = -1;
}
