/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- < gmorais-@student.42lisboa.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 11:44:57 by gmorais-          #+#    #+#             */
/*   Updated: 2023/05/05 11:44:40 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	call_case(t_stack **a, t_stack **b)
{
	int	size;

	size = ft_lstsize(*a);
	if (sorted(a))
		return ;
	if (size == 2)
		swap(a, 'a');
	if (size == 3)
		ord3(a);
	if (size == 4)
		alg_5(a, b);
	if (size == 5)
		alg_5(a, b);
	if (size > 5 && size < 500)
		alg_100(a, b);
	if (size >= 500)
		alg_500(a, b);
}

void	put_list(t_stack **s, int argc, char **argv)
{
	int	i;

	i = 0;
	while (++i < argc)
		ft_lstadd_back(s, ft_lstnew(ft_atoi(argv[i])));
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc < 3)
		return (0);
	if (check_geral(argc, argv) == 1)
	{
		ft_printf("error\n");
		return (0);
	}
	put_list(&a, argc, argv);
	get_index(&a);
	call_case(&a, &b);
	//sorted(&a);
	ft_lstclear(&a);
	ft_lstclear(&b);
}
