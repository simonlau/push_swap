#include "tst.h"
#include "../push_swap.h"

tstsuite("Operations Swap") {
	tstcase("sa") {
		t_stack *a = stack_init(3);
		stack_push(a, 2);
		stack_push(a, 1);
		sa(a);
		tstcheck(stack_is_sorted(a) == 1);
		sa(a);
		tstcheck(stack_is_sorted(a) == 0);
		stack_free(a);
	}

	tstcase("sb") {
		t_stack *b = stack_init(3);
		stack_push(b, 2);
		stack_push(b, 1);
		sb(b);
		tstcheck(stack_is_sorted(b) == 1);
		stack_free(b);
	}

	tstcase("ss") {
		t_stack *a = stack_init(3);
		t_stack *b = stack_init(3);
		stack_push(a, 2);
		stack_push(a, 1);
		stack_push(b, 5);
		stack_push(b, 4);
		ss(a, b);
		tstcheck(stack_is_sorted(a) == 1);
		tstcheck(stack_is_sorted(b) == 1);
		stack_free(a);
		stack_free(b);
	}
}
