/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operações_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:59:31 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/10 18:07:24 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/* sa e sb */
void	swap(t_stack **stack, int id)
{
	t_stack	*primeiro;
	t_stack	*segundo;


	if (id == 97 || id == 98)
		ft_printf("s%c\n", id);
	if (*stack && (*stack)->next)
	{
		primeiro = *stack;
		segundo = (*stack)->next;
		primeiro->next = segundo->next;
		segundo->next = primeiro;
		*stack = segundo;
	}
}

/* ss */
void	swapswap(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("ss\n");
	swap(stack_a, 0);
	swap(stack_b, 0);
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
