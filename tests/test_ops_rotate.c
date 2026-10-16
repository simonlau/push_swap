#include "tst.h"
#include "../push_swap.h"

tstsuite("Operations Rotate") {
	tstcase("ra") {
		t_stack *a = stack_init(4);
		stack_append(a, 3);
		stack_append(a, 1);
		stack_append(a, 2);
		ra(a);
		tstcheck(compute_disorder(a) == 0.0);
		stack_free(a);
	}

	tstcase("rb") {
		t_stack *b = stack_init(4);
		stack_append(b, 3);
		stack_append(b, 1);
		stack_append(b, 2);
		rb(b);
		tstcheck(compute_disorder(b) == 0.0);
		stack_free(b);
	}

	tstcase("rr") {
		t_stack *a = stack_init(4);
		t_stack *b = stack_init(4);
		stack_append(a, 3);
		stack_append(a, 1);
		stack_append(a, 2);
		stack_append(b, 6);
		stack_append(b, 4);
		stack_append(b, 5);
		rr(a, b);
		tstcheck(compute_disorder(a) == 0.0);
		tstcheck(compute_disorder(b) == 0.0);
		stack_free(a);
		stack_free(b);
	}
}
