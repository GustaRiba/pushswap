/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg500.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:37:26 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/26 17:12:44 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

int	check_lugar(t_stack **b, int big, int size)
{
	int		i;
	t_stack	*cursor;

	i = 0;
	cursor = *b;
	while (cursor->index != big)
	{
		i++;
		cursor = cursor->next;
	}
	size = size - i;
	if (i < size)
		return (0);
	return (1);
}

void	sort_a(t_stack **stack_a, t_stack **stack_b)
{
	while ((*stack_b))
	{
		if (!(stack_b))
			break ;
		if ((*stack_b)->index != big_index(stack_b)
			&& !check_lugar(stack_b, big_index(stack_b), ft_lstsize(*stack_b)))
			rotacao(stack_b, 98);
		else if ((*stack_b)->index != big_index(stack_b)
			&& check_lugar(stack_b, big_index(stack_b), ft_lstsize(*stack_b)))
			rev_rotacao(stack_b, 98);
		else if ((*stack_b)->index == big_index(stack_b))
			m_push(stack_b, stack_a, 97);
	}
}

void	alg_500(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	while (*stack_a)
	{
		if (i > 1 && (*stack_a)->index <= i)
		{
			m_push(stack_a, stack_b, 98);
			i++;
			rotacao(stack_b, 98);
		}
		else if ((*stack_a)->index <= i + 30)
		{
			m_push(stack_a, stack_b, 98);
			i++;
		}
		else if ((*stack_a)->index >= i)
			rotacao(stack_a, 97);
	}
	sort_a(stack_a, stack_b);
}
