/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmorais- <gmorais-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 11:15:34 by gmorais-          #+#    #+#             */
/*   Updated: 2023/04/10 16:22:49 by gmorais-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H

# define PUSHSWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <stdarg.h>
# include "ft_printf/ft_printf.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				content;
	int				index;
}	t_stack;

// listas 

t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new_node);
int		check_geral(int ac, char **av);
t_stack	*ft_lstnew(int content);
void	ate_topo_list(t_stack **stack_b, int index);
int		ft_lstsize(t_stack *lst);
void	ft_lstclear(t_stack **lst);
int		ft_lstadd_front(t_stack **lst, t_stack *new_node);
t_stack	*inicio_list(int ac, char **av);

// sort
int		sorted(t_stack **stack_a);
void	ord3(t_stack **stack_a);
void	alg_5(t_stack **stack_a, t_stack **stack_b);
void	alg_100(t_stack **stack_a, t_stack **stack_b);

// operacoes
void	swap(t_stack **stack, int id);
void	rotacao(t_stack **stack, int id);
void	rev_rotacao(t_stack **stack, int id);
//void	push_a(t_stack **stack_b, t_stack **stack_a);
//void	push_b(t_stack **stack_a, t_stack **stack_b);
void	m_push(t_stack **src, t_stack **dest, int i);

// plano b
t_stack	*ultimo_da_lista(t_stack *stack);
void	print_list(t_stack **stack);
int		big_num(t_stack *stack);
int		small_num(t_stack **stack);
void	check_pos(t_stack **stack_a, t_stack **stack_b, int c, int i);

// utils
void		get_index(t_stack **stack_a);
int			big_index(t_stack **stack_a);
int			check_index(t_stack **stack_a, int i);
int			segunda_part(t_stack **stack_a, t_stack **stack_b, int index, int *big);
void		print_index(t_stack **stack);
long long	ft_atoi(const char *str);

#endif