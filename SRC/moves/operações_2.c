/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operações_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:54:35 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/22 13:08:17 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

t_stack	*penultimo(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	current = *stack;
	if (stack == 0)
		return (0);
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	return (previous);
}

void	rev_rotacao(t_stack **stack, int id)
{
	t_stack	*last;
	t_stack	*penul;

	if (id == 97 || id == 98)
		ft_printf("rr%c\n", id);
	if (!stack)
		return ;
	penul = penultimo(stack);
	last = penul->next;
	last->next = *stack;
	*stack = last;
	penul->next = NULL;
}

/* rrr */
void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_printf("rrr\n");
	rev_rotacao(stack_a, 0);
	rev_rotacao(stack_b, 0);
}

t_stack	*ultimo_da_lista(t_stack *stack)
{
	if (!stack)
		return (0);
	while (stack->next != NULL)
		stack = stack->next;
	return (stack);
}
