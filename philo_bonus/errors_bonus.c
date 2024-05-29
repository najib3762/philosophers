/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 18:28:39 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/24 18:28:41 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	parsing_data(t_programme *prog, char **av, int ac);
static void	init_input(t_programme *prog);
static int	check_2(char **av, int *i);

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
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
	init_input(data);
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

static void	parsing_data(t_programme *prog, char **av, int ac)
{
	prog->nbr_philo = ft_atoi(av[1]);
	prog->time_to_die = ft_atoi(av[2]);
	prog->time_to_eat = ft_atoi(av[3]);
	prog->time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		prog->nbr_limit_meals = ft_atoi(av[5]);
	else
		prog->nbr_limit_meals = -1;
}

static void	init_input(t_programme *prog)
{
	prog->nbr_philo = 0;
	prog->time_to_die = 0;
	prog->time_to_eat = 0;
	prog->time_to_sleep = 0;
	prog->nbr_limit_meals = 0;
	prog->id = 0;
	prog->num_ate = 0;
	prog->time0 = get_current_time();
	prog->time_philo_dead = 0;
}
