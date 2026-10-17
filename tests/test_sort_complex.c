/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_complex.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static void	permute(int *values, unsigned int count)
{
	unsigned int	i;
	unsigned int	j;
	int			tmp;

	i = 0;
	while (i < count)
	{
		j = (i * 3 + 1) % count;
		tmp = values[i];
		values[i] = values[j];
		values[j] = tmp;
		i++;
	}
}

tstsuite("Sort Complex") {
	tstcase("sort_complex_random") {
		t_stack *a;
		t_stack *b;
		int		values[200];
		unsigned int	i;
		unsigned int	n;

		n = 200;
		i = 0;
		while (i < n)
		{
			values[i] = (int)i - 100;
			i++;
		}
		permute(values, n);
		a = stack_init(n);
		b = stack_init(n);
		fill_stack(a, values, n);
		sort_complex(a, b);
		tstcheck(a->size == n);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		i = 0;
		while (i < n)
		{
			tstcheck(a->data[i] == (int)i - 100);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_complex_large_input") {
		t_stack *a;
		t_stack *b;
		int		values[256];
		unsigned int	i;
		unsigned int	n;

		n = 256;
		i = 0;
		while (i < n)
		{
			values[i] = (int)i;
			i++;
		}
		permute(values, n);
		a = stack_init(n + 2);
		b = stack_init(n + 2);
		fill_stack(a, values, n);
		sort_complex(a, b);
		tstcheck(a->size == n);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		i = 0;
		while (i < n)
		{
			tstcheck(a->data[i] == (int)i);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_complex_nearly_sorted") {
		t_stack *a;
		t_stack *b;
		int		values[150];
		unsigned int	i;
		unsigned int	n;

		n = 150;
		i = 0;
		while (i < n)
		{
			values[i] = (int)i;
			i++;
		}
		values[10] = 149;
		values[149] = 10;
		a = stack_init(n);
		b = stack_init(n);
		fill_stack(a, values, n);
		sort_complex(a, b);
		tstcheck(a->size == n);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		i = 0;
		while (i < n)
		{
			tstcheck(a->data[i] == (int)i);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_complex_reverse_order") {
		t_stack *a;
		t_stack *b;
		int		values[120];
		unsigned int	i;
		unsigned int	n;

		n = 120;
		i = 0;
		while (i < n)
		{
			values[i] = (int)(n - 1 - i) - 60;
			i++;
		}
		a = stack_init(n);
		b = stack_init(n);
		fill_stack(a, values, n);
		sort_complex(a, b);
		tstcheck(a->size == n);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		i = 0;
		while (i < n)
		{
			tstcheck(a->data[i] == (int)i - 60);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_complex_already_sorted") {
		t_stack *a;
		t_stack *b;
		int		values[120];
		unsigned int	i;
		unsigned int	n;

		n = 120;
		i = 0;
		while (i < n)
		{
			values[i] = (int)i - 60;
			i++;
		}
		a = stack_init(n);
		b = stack_init(n);
		fill_stack(a, values, n);
		sort_complex(a, b);
		tstcheck(a->size == n);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		i = 0;
		while (i < n)
		{
			tstcheck(a->data[i] == (int)i - 60);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}
}
