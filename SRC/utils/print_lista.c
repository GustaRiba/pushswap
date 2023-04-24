/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lista.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:08:30 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/22 13:08:34 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../pushswap.h"

void	print_list(t_stack **stack)
{
	if (!*stack)
		return ;
	t_stack *current;
	current = *stack;
	while (current != NULL)
	{
		ft_printf("%d\n", current->content);
		current = current->next;
	}
}

void	print_index(t_stack **stack)
{
	if (!*stack)
		return ;
	t_stack *current;
	current = *stack;
	while (current != NULL)
	{
		ft_printf("%d\n", current->index);
		current = current->next;
	}
}
