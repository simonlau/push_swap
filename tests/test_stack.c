#include "tst.h"
#include "../push_swap.h"

tstsuite("Stack") {
	tstcase("stack_init") {
		t_stack *s = stack_init(5);
		tstcheck(s != NULL);
		tstcheck(stack_is_sorted(s) == 1);
		stack_push(s, 3);
		stack_push(s, 1);
		tstcheck(stack_is_sorted(s) == 0);
		stack_free(s);
	}

	tstcase("stack_is_sorted_empty") {
		t_stack *s = stack_init(3);
		tstcheck(stack_is_sorted(s) == 1);
		stack_free(s);
	}

	tstcase("stack_is_sorted_true") {
		t_stack *s = stack_init(3);
		stack_push(s, 1);
		stack_push(s, 2);
		stack_push(s, 3);
		tstcheck(stack_is_sorted(s) == 1);
		stack_free(s);
	}

	tstcase("stack_is_sorted_false") {
		t_stack *s = stack_init(3);
		stack_push(s, 3);
		stack_push(s, 1);
		stack_push(s, 2);
		tstcheck(stack_is_sorted(s) == 0);
		stack_free(s);
	}
}
