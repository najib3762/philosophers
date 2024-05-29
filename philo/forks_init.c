/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:16:20 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/14 21:16:21 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	forks_init(t_programme *prog)
{
	int	i;

	i = 0;
	prog->forks = malloc(sizeof(pthread_mutex_t) * prog->input.nbr_philo);
	if (prog->forks == NULL)
		return (-1);
	while (i < prog->input.nbr_philo)
	{
		if (pthread_mutex_init(&prog->forks[i], NULL) != 0)
			return (-1);
		i++;
	}
	pthread_mutex_init(&prog->race, NULL);
	pthread_mutex_init(&prog->id_thread, NULL);
	pthread_mutex_init(&prog->dead, NULL);
	pthread_mutex_init(&prog->is_time, NULL);
	pthread_mutex_init(&prog->keteb, NULL);
	return (0);
}
