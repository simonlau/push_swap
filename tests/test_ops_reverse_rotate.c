#include "tst.h"
#include "../push_swap.h"

tstsuite("Operations Reverse Rotate") {
	tstcase("rra") {
		t_stack *a = stack_init(4);
		stack_append(a, 2);
		stack_append(a, 3);
		stack_append(a, 1);
		rra(a);
		tstcheck(compute_disorder(a) == 0.0);
		stack_free(a);
	}

	tstcase("rrb") {
		t_stack *b = stack_init(4);
		stack_append(b, 2);
		stack_append(b, 3);
		stack_append(b, 1);
		rrb(b);
		tstcheck(compute_disorder(b) == 0.0);
		stack_free(b);
	}

	tstcase("rrr") {
		t_stack *a = stack_init(4);
		t_stack *b = stack_init(4);
		stack_append(a, 2);
		stack_append(a, 3);
		stack_append(a, 1);
		stack_append(b, 5);
		stack_append(b, 6);
		stack_append(b, 4);
		rrr(a, b);
		tstcheck(compute_disorder(a) == 0.0);
		tstcheck(compute_disorder(b) == 0.0);
		stack_free(a);
		stack_free(b);
	}
}
