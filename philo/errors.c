/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 21:16:11 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/14 21:16:13 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_2(char **av, int *i);

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	check_errors(t_programme *data, char **av, int ac)
{
	int		i;
	char	**tab;

	i = 1;
	while (av[i])
	{
		tab = ft_split(av[i], ' ');
		if (tab == NULL || tab[0] == NULL)
		{
			free_tab(tab);
			return (-1);
		}
		if (check_2(av, &i) == -1)
		{
			free_tab(tab);
			return (-1);
		}
		free_tab(tab);
		i++;
	}
	parsing_data(data, av, ac);
	return (0);
}

static int	check_2(char **av, int *i)
{
	long	nbr;

	if (!is_digit(av[*i]))
	{
		nbr = ft_atoi(av[*i]);
		if (nbr > 2147483647 || nbr < -2147483648)
			return (-1);
	}
	else
	{
		return (-1);
	}
	return (0);
}

void	ft_free(t_programme *prog)
{
	free(prog->philo);
	free(prog->forks);
}
