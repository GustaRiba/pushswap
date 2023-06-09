/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:04 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/27 19:05:11 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

char	char_test(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if ((av[i][j] < '0' || av[i][j] > '9') && (av[i][j] != '-'))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	duplicadas(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < ac)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	negativo(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-')
		{
			j += 1;
			if (!(av[i][j] > '0' && av[i][j] <= '9'))
				return (1);
		}
		while (av[i][j])
		{
			if (!(ft_isdigit(av[i][j])))
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (0);
}

int	erro_limit(int ac, char	**av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_atoi(av[i]) < INT_MIN || ft_atoi(av[i]) > INT_MAX)
			return (1);
		i++;
	}
	return (0);
}

int	check_geral(int ac, char **av)
{
	if (char_test(ac, av) == 1)
		return (1);
	else if (duplicadas(ac, av) == 1)
		return (1);
	else if (erro_limit(ac, av) == 1)
		return (1);
	else if (negativo(ac, av) == 1)
		return (1);
	return (0);
}
