// tirar do codigo
#include "pushswap.h"

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
