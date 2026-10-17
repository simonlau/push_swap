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

tstsuite("Strategy") {
	tstcase("select_simple") {
		t_stack	*a;
		t_stack	*b;
		int		values[] = {3, 1, 2};
		unsigned int	i;

		a = stack_init(6);
		b = stack_init(6);
		fill_stack(a, values, 3);
		select_strategy(a, b, 0);
		tstcheck(is_sorted(a));
		tstcheck(b->size == 0);
		i = 0;
		while (i < 3)
		{
			tstcheck(a->data[i] == (int)i + 1);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("select_medium") {
		t_stack	*a;
		t_stack	*b;
		int		values[20];
		unsigned int	i;

		i = 0;
		while (i < 20)
		{
			values[i] = (int)(20 - i);
			i++;
		}
		a = stack_init(20);
		b = stack_init(20);
		fill_stack(a, values, 20);
		select_strategy(a, b, 1);
		tstcheck(is_sorted(a));
		tstcheck(b->size == 0);
		i = 0;
		while (i < 20)
		{
			tstcheck(a->data[i] == (int)i + 1);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("select_complex") {
		t_stack	*a;
		t_stack	*b;
		int		values[200];
		unsigned int	i;

		i = 0;
		while (i < 200)
		{
			values[i] = (int)i - 100;
			i++;
		}
		a = stack_init(200);
		b = stack_init(200);
		fill_stack(a, values, 200);
		select_strategy(a, b, 2);
		tstcheck(is_sorted(a));
		tstcheck(b->size == 0);
		i = 0;
		while (i < 200)
		{
			tstcheck(a->data[i] == (int)i - 100);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("select_adaptive") {
		t_stack	*a;
		t_stack	*b;
		double	disorder;
		int		strategy;
		int		values[] = {5, 3, 1, 4, 2};
		unsigned int	i;

		a = stack_init(6);
		b = stack_init(6);
		fill_stack(a, values, 5);
		disorder = compute_disorder(a);
		if (disorder < 0.2)
			strategy = 0;
		else if (disorder < 0.5)
			strategy = 1;
		else
			strategy = 2;
		select_strategy(a, b, strategy);
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
