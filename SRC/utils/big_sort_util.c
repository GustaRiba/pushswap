/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_util.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 12:33:17 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/26 19:41:31 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	get_index(t_stack **stack_a)
{
	t_stack	*cursor;
	t_stack	*tmp;

	cursor = *stack_a;
	while (cursor)
	{
		cursor->index = 0;
		tmp = *stack_a;
		while (tmp)
		{
			if (cursor != tmp && cursor->content > tmp->content)
				cursor->index++;
			tmp = tmp->next;
		}
		cursor = cursor->next;
	}
}

int	check_index(t_stack **stack_a, int i)
{
	t_stack	*cursor;
	int		c;
	int		trigger;

	c = 0;
	trigger = -1;
	cursor = *stack_a;
	while (cursor)
	{
		if (cursor->index == i)
		{
			trigger = 0;
			break ;
		}
		c++;
		cursor = cursor->next;
	}
	if (trigger == -1)
		return (-1);
	return (c);
}

int	big_index(t_stack **stack_a)
{
	t_stack	*cursor;
	int		big;

	cursor = *stack_a;
	big = cursor->index;
	while (cursor)
	{
		if (cursor->index > big)
			big = cursor->index;
		cursor = cursor->next;
	}
	return (big);
}

void	ate_topo_list(t_stack **stack, int index, int o)
{
	if (index == -1)
		return ;
	if (index < (ft_lstsize(*stack) / 2))
	{
		rotacao(stack, o);
	}
	else
	{
		rev_rotacao(stack, o);
	}
}
