/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:29:59 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 18:30:01 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

long long	ft_atoi(char *str)
{
	long long	res;
	long long	negative;
	int			i;
	long long	ress;

	i = 0;
	negative = 1;
	res = 0;
	while ((str[i] && str[i] == 32) || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+')
		i++;
	while ((str[i] >= '0' && str[i] <= '9'))
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	ress = (res * negative);
	return (ress);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	is_digit(char *c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (c[i] == 32 || (c[i] >= 9 && c[i] <= 13) || c[i] == '0')
		i++;
	if (c[i] == '-')
		return (-1);
	if (c[i] == '+')
		i++;
	while ((c[i] >= '0' && c[i] <= '9') && c[i])
	{
		j++;
		i++;
	}
	if (c[i] == '\0' && j <= 10)
		return (0);
	else
		return (-1);
}
