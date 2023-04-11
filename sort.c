/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:16:41 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/11 14:05:32 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	sorted(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = *stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	printf("sorted\n");
	return (1);
}

void	ord3(t_stack **stack_a)
{
	int	big;

	big = big_num(*stack_a);
	if ((*stack_a)->content == big)
		rotacao(stack_a, 97);
	else if ((*stack_a)->next->content == big)
		rev_rotacao(stack_a, 97);
	if ((*stack_a)->content > (*stack_a)->next->content)
		swap(stack_a, 97);
}

/*void	ord4_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	int		small;
	int		size;

	size = ft_lstsize(*stack_a);
	if (size == 5)
	{
		temp = *stack_a;
		small = small_num(temp);
		check_pos(stack_a, stack_b, small, 1);
	}
	temp = *stack_a;
	small = small_num(temp);
	check_pos(stack_a, stack_b, small, 2);
	//print_list(stack_a);
	if (sorted(stack_a) == 0)
		ord3(stack_a);
	while (*stack_b)
		m_push(stack_a, stack_b, 1);
}*/

void	alg_5(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cursor;
	int		c;

	cursor = *stack_a;
	if (ft_lstsize(cursor) == 5)
	{
		c = small_num(&cursor);
		check_pos(stack_a, stack_b, c, 0);
		cursor = *stack_a;
	}
	c = small_num(&cursor);
	check_pos(stack_a, stack_b, c, 1);
	if (!(sorted(stack_a)))
		ord3(stack_a);
	while (*stack_b)
		m_push(stack_b, stack_a, 0);
}