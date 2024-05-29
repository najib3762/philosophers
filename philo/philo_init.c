/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:17:07 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/18 13:42:01 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	philo_init(t_programme *prog)
{
	int	i;
	int	j;

	prog->philo = malloc(sizeof(t_philo) * prog->input.nbr_philo);
	if (prog->philo == NULL)
		return (-1);
	i = 0;
	j = 1;
	while (i < prog->input.nbr_philo - 1)
	{
		prog->philo[i].id = i + 1;
		prog->philo[i].num_ate = 0;
		prog->philo[i].time_to_die = 0;
		prog->philo[i].fork.l_fork = i;
		prog->philo[i].fork.r_fork = j;
		i++;
		j++;
	}
	prog->philo[i].id = i + 1;
	prog->philo[i].num_ate = 0;
	prog->philo[i].time_to_die = 0;
	prog->philo[i].fork.l_fork = i;
	prog->philo[i].fork.r_fork = 0;
	return (0);
}

size_t	count_strings(const char *s, char c)
{
	size_t	nb_strings;

	nb_strings = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			while (*s != '\0' && *s != c)
				s++;
			nb_strings++;
			continue ;
		}
		s++;
	}
	return (nb_strings);
}

const char	*dup_word(char **dest, const char *src, char c)
{
	size_t	len;
	size_t	i;

	while (*src == c)
		src++;
	len = 0;
	while (src[len] != '\0' && src[len] != c)
		len++;
	*dest = (char *)malloc(sizeof(char) * (len + 1));
	if (*dest == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
	src += len + 1;
	return (src);
}

void	free_strs(char ***strs, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		free((*strs)[i]);
		i++;
	}
	free(*strs);
	*strs = NULL;
}

char	**ft_split(const char *s, char c)
{
	char	**strs;
	size_t	nbr_strings;
	size_t	i;

	nbr_strings = count_strings(s, c);
	strs = (char **)malloc(sizeof(char *) * (nbr_strings + 1));
	if (strs != NULL)
	{
		strs[nbr_strings] = NULL;
		i = 0;
		while (i < nbr_strings)
		{
			s = dup_word(strs + i, s, c);
			if (s == NULL)
			{
				free_strs(&strs, i);
				break ;
			}
			i++;
		}
	}
	return (strs);
}
