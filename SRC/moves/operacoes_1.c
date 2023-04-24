/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operações_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:59:31 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/22 13:08:14 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

/* sa e sb */
void	swap(t_stack **s, int i)
{
	t_stack	*cursor;
	t_stack	*tmp;

	cursor = *s;
	tmp = cursor->next->next;
	cursor = cursor->next;
	cursor->next = *s;
	*s = cursor;
	cursor = cursor->next;
	cursor->next = tmp;
	if (i == 97)
		ft_printf("sa\n");
	if (i == 98)
		ft_printf("sb\n");
}

void	m_ss(t_stack **a, t_stack **b, int i)
{
	swap(a, 2);
	swap(b, 2);
	if (i == 2)
		ft_printf("ss\n");
}


/* ra e rb */
void	rotacao(t_stack **s, int i)
{
	t_stack	*tmp;
	t_stack	*cursor;

	cursor = ft_lstlast(*s);
	cursor->next = *s;
	cursor = *s;
	tmp = (*s)->next;
	cursor->next = NULL;
	*s = tmp;
	if (i == 97)
		ft_printf("ra\n");
	if (i == 98)
		ft_printf("rb\n");
}


/* rr */
void	rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rr\n");
	rotacao(stack_a, 0);
	rotacao(stack_b, 0);
}
