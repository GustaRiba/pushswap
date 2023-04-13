/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg100.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:39:04 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/13 12:17:58 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	for_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		chunk;
	int		c;

	chunk = 30;
	c = 0;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index < chunk)
		{
			m_push(stack_a, stack_b, 1);
			c++;
		}
		else if (c == chunk)
		{
			printf("c var: %d\n", c);
			if (size > 100)
				chunk += 30;
			else
				chunk += 15;
		}
		else
		{
			ate_topo_list(stack_a, check_index(stack_a, (*stack_a)->index));
		}
	}
	
	print_index(stack_b);
	printf("\n");
}

int	put_in_a_2(t_stack **stack_a, t_stack **stack_b, int *big, int index)
{
	if (index == 2 && (check_index(stack_b, ((*big) - 1)) == 0))
	{
		m_push(stack_b, stack_a, 0);
		(*big)--;
		rotacao(stack_b, 98);
		m_push(stack_b, stack_a, 0);
		(*big)--;
		swap(stack_a, 98);
		index = check_index(stack_b, (*big));
	}
	else if ((check_index(stack_b, ((*big) - 1)) == 0))
	{
		m_push(stack_b, stack_a, 0);
		index = check_index(stack_b, (*big));
	}
	else
	{
		ate_topo_list(stack_b, index);
		index = check_index(stack_b, (*big));
	}
	return (index);
}

int	para_a(t_stack **stack_a, t_stack **stack_b, int *big, int index)
{

	if ((*stack_a) && (*stack_a)->next && (*stack_a)->content > (*stack_a)->next->content)
	{
		swap(stack_a, 97);
		(*big)--;
		index = check_index(stack_b, *big);
	}
	else if (check_index(stack_b, (*big)) == 0)
	{
		m_push(stack_b, stack_a, 0);
		(*big)--;
		index = check_index(stack_b, (*big));
	}
	else if (index == 1 && (check_index(stack_b, (*big) - 1)) == 0)
	{
		swap(stack_b, 98);
		index = check_index(stack_b, (*big));
	}
	else
		index = put_in_a_2(stack_a, stack_b, big, index);
	return (index);
}

void	alg_100(t_stack **stack_a, t_stack **stack_b)
{
	int	big;
	int	index;

	for_b(stack_a, stack_b, ft_lstsize(*stack_a));
	big = big_index(stack_b);
	index = check_index(stack_b, big);
	while ((*stack_b) != NULL && index == check_index(stack_b, big))
		index = para_a(stack_a, stack_b, &big, index);
	if ((*stack_b) == NULL && (*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, 97);
}
