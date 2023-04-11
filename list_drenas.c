/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_drenas.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 12:22:49 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/03 14:32:27 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_lstlast(t_stack *lst)
{
	if (!lst)
		return (0);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new_node)
{
	t_stack	*last_node;

	if (!lst || !new_node)
		return ;
	if (!*lst)
		*lst = new_node;
	else
	{
		last_node = ft_lstlast(*lst);
		last_node->next = new_node;
	}
}

int	ft_lstadd_front(t_stack **lst, t_stack *new_node)
{
	if (!lst || !new_node)
		return (0);
	new_node->next = *lst;
	*lst = new_node;
	return (1);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*lst1;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		lst1 = (*lst)->next;
		free(*lst);
		*lst = lst1;
	}
	free(lst1);
}


t_stack	*ft_lstnew(int content)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	return (new_node);
}
