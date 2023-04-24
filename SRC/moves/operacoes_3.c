/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operacoes_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 11:35:31 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/22 13:08:20 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

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