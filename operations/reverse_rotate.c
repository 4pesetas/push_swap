#include "../push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || (*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->prev->next = NULL;
	last_node->next=*stack;
	last_node->prev = NULL;
	*stacl = last_node;
	lat_node->next->prev = last;
}
void	rra()