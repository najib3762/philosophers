/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namoussa <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 13:24:29 by namoussa          #+#    #+#             */
/*   Updated: 2024/05/25 13:24:31 by namoussa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
