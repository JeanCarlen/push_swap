#include "push_swap.h"

void	jifas(t_list **stack_a, t_list **stack_b)
{
	t_place	*plc;
	t_list *ptr;

	ptr = *stack_a;
	plc = malloc(sizeof(t_place));
	if(!plc)
		return;
	plc->median = median(stack_a);
	init_place(stack_a, stack_b, plc);
	rotate_to(stack_a, gimi_median(stack_a, plc->median));
	printf("median is : %d\n", plc->median);
	pb(stack_a, stack_b);
	while(!check_sorted(stack_a) || is_empty(*stack_b) == 0)
	{
		init_place(stack_a, stack_b, plc);
		if ((!(plc->top_a->content < plc->bot_b->content)) && (!(plc->top_a->content > plc->top_b->content)))
		{
			sa(stack_a, 'a');
			init_place(stack_a, stack_b, plc);
		}
		rotate_to(stack_a, compare(plc));
		pb(stack_a, stack_b);
		init_place(stack_a, stack_b, plc);
		if (plc->top_b->content < plc->top_b->next->content)
			rb(stack_b, 'b');
		if (is_empty(*stack_a) == 1)
		{
			while (is_empty(*stack_b) == 0)
				pa(stack_a, stack_b);
		}
		solver(stack_a, stack_b, plc);
		print_lst(stack_a, stack_b);
		printf("----------\n");
	}
	free(plc);
}

int	solver(t_list **stack_a, t_list **stack_b, t_place *plc)
{
	init_place(stack_a, stack_b, plc);
	if (plc->top_a->content < plc->top_b->content && plc->top_a->content > plc->bot_b->content 
		&& plc->bot_a->content < plc->top_b->content && plc->bot_a->content > plc->bot_b->content)
	{
		printf("start solver \n");
		if (plc->bot_b->content < plc->top_a->content && plc->bot_b->content < plc->bot_a->content)
		{
			rrb(stack_b, 'b');
			pa(stack_a, stack_b);
			sa(stack_a, 'a');
			return (1);
		}
	}
	return (0);
}

int is_empty(t_list *list)
{
	if( !list )
		return 1;
	return 0;
}

void	rotate_to_b(t_list **stack, t_list *ptr)
{
	int		size;
	int		i;
	t_list	*top;
	int		rb_tog;
	
	top = *stack;
	size = ft_lstsize(*stack);
	i = 0;
	rb_tog = 0;
	while (i <= size / 2 && top != ptr)
	{
		top = top->next;
		i++;
	}
	if (i <= size / 2)
		rb_tog = 1;
	while (*stack != ptr)
	{
		if (rb_tog)
			rb(stack, 'b');
		else
			rrb(stack, 'b');
	}
}