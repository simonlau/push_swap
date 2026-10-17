/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_simple.c                                 :+:      :+:    :+:   */
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

tstsuite("Sort Simple") {
	tstcase("sort_zero_elements") {
		t_stack *a;
		t_stack *b;

		a = stack_init(5);
		b = stack_init(5);
		sort_simple(a, b);
		tstcheck(a != NULL && b != NULL);
		tstcheck(a->size == 0);
		tstcheck(b->size == 0);
		tstcheck(compute_disorder(a) == 0.0);
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_one_element") {
		t_stack *a;
		t_stack *b;
		int expected[] = {42};

		a = stack_init(5);
		b = stack_init(5);
		fill_stack(a, expected, 1);
		sort_simple(a, b);
		tstcheck(a->size == 1);
		tstcheck(b->size == 0);
		tstcheck(a->data[0] == 42);
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_two_elements") {
		t_stack *a;
		t_stack *b;
		int expected[] = {1, 2};

		a = stack_init(5);
		b = stack_init(5);
		fill_stack(a, expected, 2);
		sort_simple(a, b);
		tstcheck(a->size == 2);
		tstcheck(b->size == 0);
		tstcheck(a->data[0] == 1);
		tstcheck(a->data[1] == 2);
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_two_elements_reversed") {
		t_stack *a;
		t_stack *b;
		int reversed[] = {2, 1};

		a = stack_init(5);
		b = stack_init(5);
		fill_stack(a, reversed, 2);
		sort_simple(a, b);
		tstcheck(a->size == 2);
		tstcheck(b->size == 0);
		tstcheck(a->data[0] == 1);
		tstcheck(a->data[1] == 2);
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_three_elements") {
		t_stack *a;
		t_stack *b;
		int permutations[6][3] = {
			{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
			{2, 3, 1}, {3, 1, 2}, {3, 2, 1}
		};
		int p;

		p = 0;
		while (p < 6)
		{
			a = stack_init(5);
			b = stack_init(5);
			fill_stack(a, permutations[p], 3);
			sort_simple(a, b);
			tstcheck(a->size == 3);
			tstcheck(b->size == 0);
			tstcheck(a->data[0] == 1);
			tstcheck(a->data[1] == 2);
			tstcheck(a->data[2] == 3);
			stack_free(a);
			stack_free(b);
			p++;
		}
	}

	tstcase("sort_four_elements") {
		t_stack *a;
		t_stack *b;
		int cases[4][4] = {
			{2, 1, 4, 3}, {3, 2, 1, 4}, {4, 3, 2, 1}, {1, 3, 4, 2}
		};
		int c;

		c = 0;
		while (c < 4)
		{
			a = stack_init(5);
			b = stack_init(5);
			fill_stack(a, cases[c], 4);
			sort_simple(a, b);
			tstcheck(a->size == 4);
			tstcheck(b->size == 0);
			tstcheck(a->data[0] == 1);
			tstcheck(a->data[1] == 2);
			tstcheck(a->data[2] == 3);
			tstcheck(a->data[3] == 4);
			stack_free(a);
			stack_free(b);
			c++;
		}
	}

	tstcase("sort_five_elements") {
		t_stack *a;
		t_stack *b;
		int cases[4][5] = {
			{5, 4, 3, 2, 1}, {3, 5, 1, 4, 2}, {2, 4, 1, 5, 3}, {1, 2, 3, 5, 4}
		};
		int c;

		c = 0;
		while (c < 4)
		{
			a = stack_init(6);
			b = stack_init(6);
			fill_stack(a, cases[c], 5);
			sort_simple(a, b);
			tstcheck(a->size == 5);
			tstcheck(b->size == 0);
			tstcheck(a->data[0] == 1);
			tstcheck(a->data[1] == 2);
			tstcheck(a->data[2] == 3);
			tstcheck(a->data[3] == 4);
			tstcheck(a->data[4] == 5);
			stack_free(a);
			stack_free(b);
			c++;
		}
	}

	tstcase("sort_reverse_order") {
		t_stack *a;
		t_stack *b;
		int reverse[5] = {5, 4, 3, 2, 1};

		a = stack_init(6);
		b = stack_init(6);
		fill_stack(a, reverse, 5);
		sort_simple(a, b);
		tstcheck(a->size == 5);
		tstcheck(b->size == 0);
		tstcheck(a->data[0] == 1);
		tstcheck(a->data[1] == 2);
		tstcheck(a->data[2] == 3);
		tstcheck(a->data[3] == 4);
		tstcheck(a->data[4] == 5);
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_already_sorted") {
		t_stack *a;
		t_stack *b;
		int sorted[5] = {1, 2, 3, 4, 5};

		a = stack_init(6);
		b = stack_init(6);
		fill_stack(a, sorted, 5);
		sort_simple(a, b);
		tstcheck(a->size == 5);
		tstcheck(b->size == 0);
		tstcheck(a->data[0] == 1);
		tstcheck(a->data[1] == 2);
		tstcheck(a->data[2] == 3);
		tstcheck(a->data[3] == 4);
		tstcheck(a->data[4] == 5);
		stack_free(a);
		stack_free(b);
	}
}
