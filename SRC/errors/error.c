/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 16:33:04 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/22 13:08:00 by gmorais-         ###   ########.fr       */
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

int	negativo(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][0] == '-')
		{
			j++;
			if (!ft_isdigit(argv[i][j]) || argv[i][j] == '0')
				exit(write(2, "Error\n", 6));
		}
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])))
				exit(write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (1);
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
