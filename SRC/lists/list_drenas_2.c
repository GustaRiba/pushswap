/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_drenas_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:31:00 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/22 13:08:07 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

t_stack	*inicio_list(int ac, char **av)
{
	t_stack		*stack_a;
	long int	nb;
	int			i;

	stack_a = NULL;
	nb = 0;
	i = 1;
	while (i < ac)
	{
		nb = ft_atoi(av[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			ft_printf("error\n");
		if (i == 1)
			stack_a = ft_lstnew((int)nb);
		else
			ft_lstadd_back(&stack_a, ft_lstnew((int) nb));
		i++;
	}
	return (stack_a);
}

int	ft_lstsize(t_stack *lst)
{
	int	i;

	i = 0;
	if (!lst)
		return (0);
	while (lst != NULL)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}