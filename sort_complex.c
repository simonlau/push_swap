/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	init_sorted(t_stack *a, int *sorted, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	int				key;

	i = 0;
	while (i < size)
	{
		sorted[i] = a->data[i];
		i++;
	}
	i = 1;
	while (i < size)
	{
		key = sorted[i];
		j = i;
		while (j > 0 && sorted[j - 1] > key)
		{
			sorted[j] = sorted[j - 1];
			j--;
		}
		sorted[j] = key;
		i++;
	}
}

static unsigned int	rank_of(const int *sorted, unsigned int size, int value)
{
	unsigned int	lo;
	unsigned int	hi;
	unsigned int	mid;

	lo = 0;
	hi = size;
	while (lo < hi)
	{
		mid = (lo + hi) / 2;
		if (sorted[mid] < value)
			lo = mid + 1;
		else
			hi = mid;
	}
	return (lo);
}

static void	radix_pass(t_stack *a, t_stack *b, const int *sorted)
{
	unsigned int	size;
	unsigned int	passes;
	unsigned int	bit;
	unsigned int	i;

	size = a->size;
	passes = 0;
	while ((size - 1) >> passes)
		passes++;
	bit = 0;
	while (bit < passes)
	{
		i = 0;
		while (i < size)
		{
			if ((rank_of(sorted, size, a->data[0]) >> bit) & 1)
				ra(a);
			else
				pb(a, b);
			i++;
		}
		while (b->size > 0)
			pa(a, b);
		bit++;
	}
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int	*sorted;

	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	sorted = (int *)malloc(sizeof(int) * a->size);
	if (!sorted)
		return ;
	init_sorted(a, sorted, a->size);
	radix_pass(a, b, sorted);
	free(sorted);
}
