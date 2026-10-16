#include "tst.h"
#include "../push_swap.h"

tstsuite("Stack") {
	tstcase("stack_init") {
		t_stack *s = stack_init(5);
		tstcheck(s != NULL);
		tstcheck(compute_disorder(s) == 0.0);
		stack_append(s, 3);
		stack_append(s, 1);
		tstcheck(compute_disorder(s) > 0.0);
		stack_free(s);
	}

	tstcase("compute_disorder_empty") {
		t_stack *s = stack_init(3);
		tstcheck(compute_disorder(s) == 0.0);
		stack_free(s);
	}

	tstcase("compute_disorder_sorted") {
		t_stack *s = stack_init(3);
		stack_append(s, 1);
		stack_append(s, 2);
		stack_append(s, 3);
		tstcheck(compute_disorder(s) == 0.0);
		stack_free(s);
	}

	tstcase("compute_disorder_partial") {
		t_stack *s = stack_init(3);
		stack_append(s, 3);
		stack_append(s, 1);
		stack_append(s, 2);
		tstcheck(compute_disorder(s) > 0.0);
		tstcheck(compute_disorder(s) < 1.0);
		stack_free(s);
	}
}
