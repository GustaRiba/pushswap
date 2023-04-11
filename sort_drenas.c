/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_drenas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:56:15 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/06 14:49:32 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	big_num(t_stack *stack)
{
	int	big;

	big = stack->content;
	while (stack)
	{
		if (stack->content > big)
			big = stack->content;
		stack = stack->next;
	}
	return (big);
}

int	small_num(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*small;
	int		i;

	temp = *stack;
	small = *stack;
	i = 0;
	while (temp)
	{
		if (temp->content < small->content)
			small = temp;
		temp = temp->next;
	}
	temp = *stack;
	while (temp != small)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

void	check_pos(t_stack **stack_a, t_stack **stack_b, int c, int i)
{
	if (c > 2)
	{
		if (i == 1)
			c = 4 - c;
		else
			c = 5 - c;
		while (c)
		{
			rev_rotacao(stack_a, 97);
			c--;
		}
	}
	else
	{
		while (c)
		{
			rotacao(stack_a, 97);
			c--;
		}
	}
	m_push(stack_a, stack_b, 1);
}

long long	ft_atoi(const char *str)
{
	int			i;
	int			signal;
	long long	result;

	i = 0;
	signal = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
	{
		signal = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
	{
		result *= 10;
		result += str[i] - 48;
		i++;
	}
	return (result * signal);
}
