/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_sort_medium.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 15:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tst.h"
#include "../push_swap.h"
#include <unistd.h>

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
	int				tmp;

	i = 0;
	while (i < count)
	{
		j = (i * 7 + 3) % count;
		tmp = values[i];
		values[i] = values[j];
		values[j] = tmp;
		i++;
	}
}

static int	is_op(const char *tok)
{
	static const char	*ops[] = {"sa", "sb", "ss", "pa", "pb", "ra", "rb",
		"rr", "rra", "rrb", "rrr", NULL};
	int					i;

	i = 0;
	while (ops[i])
	{
		if (strcmp(tok, ops[i]) == 0)
			return (1);
		i++;
	}
	return (0);
}

static long	capture_sort(t_stack *a, t_stack *b, int *valid)
{
	FILE	*f;
	int		fd;
	int		saved;
	char	buf[65536];
	ssize_t	n;
	long	lines;
	char	*tok;

	*valid = 1;
	f = tmpfile();
	if (!f)
		return (-1);
	fd = fileno(f);
	saved = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	sort_medium(a, b);
	fflush(NULL);
	dup2(saved, STDOUT_FILENO);
	close(saved);
	n = pread(fd, buf, sizeof(buf) - 1, 0);
	if (n < 0)
		n = 0;
	buf[n] = '\0';
	lines = 0;
	tok = strtok(buf, "\n");
	while (tok)
	{
		if (!is_op(tok))
			*valid = 0;
		lines++;
		tok = strtok(NULL, "\n");
	}
	fclose(f);
	return (lines);
}

tstsuite("Sort Medium") {
	tstcase("sort_medium_five_elements") {
		t_stack *a;
		t_stack *b;
		int		values[5] = {3, 5, 1, 4, 2};
		unsigned int	i;

		a = stack_init(5);
		b = stack_init(5);
		fill_stack(a, values, 5);
		sort_medium(a, b);
		tstcheck(a->size == 5);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		i = 0;
		while (i < 5)
		{
			tstcheck(a->data[i] == (int)i + 1);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_medium_sizes_five_to_twenty") {
		t_stack *a;
		t_stack *b;
		int		values[20];
		unsigned int	i;
		unsigned int	n;

		n = 5;
		while (n <= 20)
		{
			i = 0;
			while (i < n)
			{
				values[i] = (int)(n - i);
				i++;
			}
			a = stack_init(n);
			b = stack_init(n);
			fill_stack(a, values, n);
			sort_medium(a, b);
			tstcheck(a->size == n);
			tstcheck(b->size == 0);
			tstcheck(is_sorted(a));
			i = 0;
			while (i < n)
			{
				tstcheck(a->data[i] == (int)i + 1);
				i++;
			}
			stack_free(a);
			stack_free(b);
			n++;
		}
	}

	tstcase("sort_medium_random_fifty") {
		t_stack *a;
		t_stack *b;
		int		values[50];
		unsigned int	i;
		unsigned int	n;

		n = 50;
		i = 0;
		while (i < n)
		{
			values[i] = (int)i - 25;
			i++;
		}
		permute(values, n);
		a = stack_init(n);
		b = stack_init(n);
		fill_stack(a, values, n);
		sort_medium(a, b);
		tstcheck(a->size == n);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		i = 0;
		while (i < n)
		{
			tstcheck(a->data[i] == (int)i - 25);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_medium_nearly_sorted_hundred") {
		t_stack *a;
		t_stack *b;
		int		values[100];
		unsigned int	i;
		unsigned int	n;

		n = 100;
		i = 0;
		while (i < n)
		{
			values[i] = (int)i;
			i++;
		}
		values[10] = 99;
		values[99] = 10;
		a = stack_init(n);
		b = stack_init(n);
		fill_stack(a, values, n);
		sort_medium(a, b);
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

	tstcase("sort_medium_reverse_hundred") {
		t_stack *a;
		t_stack *b;
		int		values[100];
		unsigned int	i;
		unsigned int	n;

		n = 100;
		i = 0;
		while (i < n)
		{
			values[i] = (int)(n - i);
			i++;
		}
		a = stack_init(n);
		b = stack_init(n);
		fill_stack(a, values, n);
		sort_medium(a, b);
		tstcheck(a->size == n);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		i = 0;
		while (i < n)
		{
			tstcheck(a->data[i] == (int)i + 1);
			i++;
		}
		stack_free(a);
		stack_free(b);
	}

	tstcase("sort_medium_emits_only_valid_operations") {
		t_stack *a;
		t_stack *b;
		int		values[100];
		unsigned int	i;
		unsigned int	n;
		long		ops;
		int			valid;

		n = 100;
		i = 0;
		while (i < n)
		{
			values[i] = (int)i - 50;
			i++;
		}
		permute(values, n);
		a = stack_init(n);
		b = stack_init(n);
		fill_stack(a, values, n);
		ops = capture_sort(a, b, &valid);
		tstcheck(valid);
		tstcheck(a->size == n);
		tstcheck(b->size == 0);
		tstcheck(is_sorted(a));
		tstcheck(ops > 0);
		tstcheck(ops < 900);
		stack_free(a);
		stack_free(b);
	}
}
