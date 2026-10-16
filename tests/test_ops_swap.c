#include "tst.h"
#include "../push_swap.h"

tstsuite("Operations Swap") {
	tstcase("sa") {
		t_stack *a = stack_init(3);
		stack_append(a, 2);
		stack_append(a, 1);
		sa(a);
		tstcheck(compute_disorder(a) == 0.0);
		sa(a);
		tstcheck(compute_disorder(a) > 0.0);
		stack_free(a);
	}

	tstcase("sb") {
		t_stack *b = stack_init(3);
		stack_append(b, 2);
		stack_append(b, 1);
		sb(b);
		tstcheck(compute_disorder(b) == 0.0);
		stack_free(b);
	}

	tstcase("ss") {
		t_stack *a = stack_init(3);
		t_stack *b = stack_init(3);
		stack_append(a, 2);
		stack_append(a, 1);
		stack_append(b, 5);
		stack_append(b, 4);
		ss(a, b);
		tstcheck(compute_disorder(a) == 0.0);
		tstcheck(compute_disorder(b) == 0.0);
		stack_free(a);
		stack_free(b);
	}
}
