/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:28:49 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 18:28:50 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

size_t	get_current_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		write(2, "gettimeofday() error\n", 22);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long long	new_time(long long time)
{
	if (time > 0)
		return (get_current_time() - time);
	return (0);
}

int	ft_usleep(size_t time)
{
	size_t	start;

	start = get_current_time();
	usleep((time * 1000) - 20000);
	while (((get_current_time() - start) < time))
		;
	return (0);
}
