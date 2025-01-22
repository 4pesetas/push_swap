#include "../push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || (*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = 

}