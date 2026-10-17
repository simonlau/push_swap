#include "tst.h"
#include "../push_swap.h"

static void	fill_stack(t_stack *a, const int *values, unsigned int count)
{
	unsigned int	i;

	i = 0;
	while (i < count)
	{
		stack_append(a, values[i]);
		i++;
	}
}

static int	is_sorted(t_stack *a)
{
	unsigned int	i;

	i = 1;
	while (i < a->size)
	{
		if (a->data[i - 1] > a->data[i])
			return (0);
		i++;
	}
	return (1);
}

tstsuite("Sort Adaptive") {
	tstcase("adaptive_low_disorder") {
		t_stack	*a;
		t_stack	*b;
		int		values[] = {1, 2, 3, 4, 5};
		unsigned int	i;

		a = stack_init(6);
		b = stack_init(6);
		fill_stack(a, values, 5);
		tstcheck(compute_disorder(a) < 0.2);
		sort_adaptive(a, b);
		tstcheck(is_sorted(a));
		tstcheck(b->size == 0);
		i = 0;
		while (i < 5)
		{
			tstcheck(a->data[i] == (int)i + 1);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("adaptive_medium_disorder") {
		t_stack	*a;
		t_stack	*b;
		int		values[] = {1, 3, 5, 2, 4, 6, 8, 7, 9, 10};
		unsigned int	i;

		a = stack_init(11);
		b = stack_init(11);
		fill_stack(a, values, 10);
		sort_adaptive(a, b);
		tstcheck(is_sorted(a));
		tstcheck(b->size == 0);
		i = 0;
		while (i < 10)
		{
			tstcheck(a->data[i] == (int)i + 1);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("adaptive_high_disorder") {
		t_stack	*a;
		t_stack	*b;
		int		values[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
		unsigned int	i;

		a = stack_init(11);
		b = stack_init(11);
		fill_stack(a, values, 10);
		tstcheck(compute_disorder(a) == 1.0);
		sort_adaptive(a, b);
		tstcheck(is_sorted(a));
		tstcheck(b->size == 0);
		i = 0;
		while (i < 10)
		{
			tstcheck(a->data[i] == (int)i + 1);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("adaptive_selects_correct_strategy") {
		t_stack	*a;
		t_stack	*b;
		int		values[] = {4, 1, 5, 2, 3};
		unsigned int	i;

		a = stack_init(6);
		b = stack_init(6);
		fill_stack(a, values, 5);
		sort_adaptive(a, b);
		tstcheck(is_sorted(a));
		tstcheck(b->size == 0);
		i = 0;
		while (i < 5)
		{
			tstcheck(a->data[i] == (int)i + 1);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}
}
