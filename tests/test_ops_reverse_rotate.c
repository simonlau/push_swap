#include "tst.h"
#include "../push_swap.h"

tstsuite("Operations Reverse Rotate") {
	tstcase("rra") {
		t_stack *a = stack_init(4);
		stack_push(a, 2);
		stack_push(a, 3);
		stack_push(a, 1);
		rra(a);
		tstcheck(stack_is_sorted(a) == 1);
		stack_free(a);
	}

	tstcase("rrb") {
		t_stack *b = stack_init(4);
		stack_push(b, 2);
		stack_push(b, 3);
		stack_push(b, 1);
		rrb(b);
		tstcheck(stack_is_sorted(b) == 1);
		stack_free(b);
	}

	tstcase("rrr") {
		t_stack *a = stack_init(4);
		t_stack *b = stack_init(4);
		stack_push(a, 2);
		stack_push(a, 3);
		stack_push(a, 1);
		stack_push(b, 5);
		stack_push(b, 6);
		stack_push(b, 4);
		rrr(a, b);
		tstcheck(stack_is_sorted(a) == 1);
		tstcheck(stack_is_sorted(b) == 1);
		stack_free(a);
		stack_free(b);
	}
}
