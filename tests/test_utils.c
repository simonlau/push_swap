#include "tst.h"
#include "../push_swap.h"
#include <limits.h>

tstsuite("Utils") {
	tstcase("ft_abs_positive") {
		tstcheck(ft_abs(0) == 0);
		tstcheck(ft_abs(5) == 5);
		tstcheck(ft_abs(100) == 100);
	}

	tstcase("ft_abs_negative") {
		tstcheck(ft_abs(-5) == 5);
		tstcheck(ft_abs(-100) == 100);
		tstcheck(ft_abs(-1) == 1);
	}

	tstcase("ft_min") {
		tstcheck(ft_min(3, 7) == 3);
		tstcheck(ft_min(7, 3) == 3);
		tstcheck(ft_min(5, 5) == 5);
		tstcheck(ft_min(INT_MIN, INT_MAX) == INT_MIN);
	}

	tstcase("ft_max") {
		tstcheck(ft_max(3, 7) == 7);
		tstcheck(ft_max(7, 3) == 7);
		tstcheck(ft_max(5, 5) == 5);
		tstcheck(ft_max(INT_MIN, INT_MAX) == INT_MAX);
	}

	tstcase("compute_disorder_sorted") {
		t_stack *s = stack_init(4);
		stack_append(s, 1);
		stack_append(s, 2);
		stack_append(s, 3);
		tstcheck(compute_disorder(s) == 0.0);
		stack_free(s);
	}

	tstcase("compute_disorder_reverse_sorted") {
		t_stack *s = stack_init(4);
		stack_append(s, 3);
		stack_append(s, 2);
		stack_append(s, 1);
		tstcheck(compute_disorder(s) == 1.0);
		stack_free(s);
	}

	tstcase("compute_disorder_partial") {
		t_stack *s = stack_init(4);
		stack_append(s, 2);
		stack_append(s, 1);
		stack_append(s, 3);
		tstcheck(compute_disorder(s) > 0.0);
		tstcheck(compute_disorder(s) < 1.0);
		stack_free(s);
	}

	tstcase("compute_disorder_empty") {
		t_stack *s = stack_init(3);
		tstcheck(compute_disorder(s) == 0.0);
		stack_free(s);
	}

	tstcase("compute_disorder_single") {
		t_stack *s = stack_init(3);
		stack_append(s, 42);
		tstcheck(compute_disorder(s) == 0.0);
		stack_free(s);
	}
}
