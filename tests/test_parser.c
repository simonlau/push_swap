#include "tst.h"
#include "../push_swap.h"

tstsuite("Parser") {
	tstcase("parse_valid_args") {
		char	*args[] = {"push_swap", "1", "2", "3"};
		t_stack	*a = stack_init(5);

		tstcheck(parse_args(4, args, a) == 0);
		tstcheck(compute_disorder(a) == 0.0);
		stack_free(a);
	}

	tstcase("parse_valid_negative") {
		char	*args[] = {"push_swap", "0", "-5", "42"};
		t_stack	*a = stack_init(5);

		tstcheck(parse_args(4, args, a) == 0);
		tstcheck(compute_disorder(a) > 0.0);
		stack_free(a);
	}

	tstcase("parse_valid_int_limits") {
		char	*args[] = {"push_swap", "-2147483648", "2147483647"};
		t_stack	*a = stack_init(4);

		tstcheck(parse_args(3, args, a) == 0);
		stack_free(a);
	}

	tstcase("parse_invalid_non_numeric") {
		char	*args[] = {"push_swap", "1", "abc"};
		t_stack	*a = stack_init(5);

		tstcheck(parse_args(3, args, a) == 1);
		stack_free(a);
	}

	tstcase("parse_invalid_overflow") {
		char	*args[] = {"push_swap", "2147483648"};
		t_stack	*a = stack_init(5);

		tstcheck(parse_args(2, args, a) == 1);
		stack_free(a);
	}

	tstcase("parse_invalid_underflow") {
		char	*args[] = {"push_swap", "-2147483649"};
		t_stack	*a = stack_init(5);

		tstcheck(parse_args(2, args, a) == 1);
		stack_free(a);
	}

	tstcase("parse_duplicates") {
		char	*args[] = {"push_swap", "3", "1", "3"};
		t_stack	*a = stack_init(5);

		tstcheck(parse_args(4, args, a) == 1);
		stack_free(a);
	}

	tstcase("parse_empty") {
		char	*args[] = {"push_swap"};
		t_stack	*a = stack_init(3);

		tstcheck(parse_args(1, args, a) == 0);
		tstcheck(compute_disorder(a) == 0.0);
		stack_free(a);
	}
}
