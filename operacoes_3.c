/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:35:31 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/17 15:57:31 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* pa e pb */
/*static void	push(t_stack **src, t_stack **dest)
{
	t_stack	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pa\n");
}

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pb\n");
}*/

void	m_push(t_stack **src, t_stack **dest, int i)
{
	t_stack	*cursor_src;
	t_stack	*cursor_dest;
	t_stack	*tmp;

	cursor_src = *src;
	if (!*dest)
	{
		*dest = *src;
		cursor_dest = *dest;
		*src = cursor_src->next;
		cursor_dest->next = NULL;
	}
	else
	{
		tmp = *dest;
		*dest = *src;
		cursor_dest = *dest;
		*src = cursor_src->next;
		cursor_dest->next = tmp;
	}
	if (i == 97)
		ft_printf("pa\n");
	if (i == 98)
		ft_printf("pb\n");
}