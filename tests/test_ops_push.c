#include "tst.h"
#include "../push_swap.h"

tstsuite("Operations Push") {
	tstcase("pa") {
		t_stack *a = stack_init(4);
		t_stack *b = stack_init(4);
		stack_push(b, 3);
		stack_push(b, 1);
		pa(a, b);
		tstcheck(compute_disorder(a) == 0.0);
		tstcheck(compute_disorder(b) == 0.0);
		pa(a, b);
		tstcheck(compute_disorder(a) == 0.0);
		tstcheck(compute_disorder(b) == 0.0);
		stack_free(a);
		stack_free(b);
	}

	tstcase("pb") {
		t_stack *a = stack_init(4);
		t_stack *b = stack_init(4);
		stack_push(a, 3);
		stack_push(a, 1);
		pb(a, b);
		tstcheck(compute_disorder(a) == 0.0);
		tstcheck(compute_disorder(b) == 0.0);
		pb(a, b);
		tstcheck(compute_disorder(a) == 0.0);
		tstcheck(compute_disorder(b) == 0.0);
		stack_free(a);
		stack_free(b);
	}
}
