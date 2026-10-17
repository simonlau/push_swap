/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 15:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static void	rotate_to_chunk(t_stack *a, const int *sorted, unsigned int lo,
		unsigned int hi)
{
	unsigned int	fwd;
	unsigned int	bwd;
	unsigned int	i;

	fwd = a->size;
	bwd = a->size;
	i = 0;
	while (i < a->size)
	{
		if (a->data[i] >= sorted[lo] && a->data[i] <= sorted[hi])
		{
			if (fwd == a->size)
				fwd = i;
			bwd = a->size - i;
		}
		i++;
	}
	if (fwd <= bwd)
		while (fwd-- > 0)
			ra(a);
	else
		while (bwd-- > 0)
			rra(a);
}

static void	push_chunks(t_stack *a, t_stack *b, const int *sorted,
		unsigned int size)
{
	unsigned int	n;
	unsigned int	lo;
	unsigned int	hi;
	unsigned int	left;

	n = a->size;
	lo = 0;
	while (lo < n)
	{
		hi = lo + size;
		if (hi > n)
			hi = n;
		hi--;
		left = hi - lo + 1;
		while (left > 0)
		{
			rotate_to_chunk(a, sorted, lo, hi);
			pb(a, b);
			left--;
		}
		lo += size;
	}
}

static void	push_back(t_stack *a, t_stack *b)
{
	unsigned int	max_i;
	unsigned int	i;

	while (b->size > 0)
	{
		max_i = 0;
		i = 0;
		while (++i < b->size)
		{
			if (b->data[i] > b->data[max_i])
				max_i = i;
		}
		if (max_i <= b->size / 2)
		{
			while (max_i-- > 0)
				rb(b);
		}
		else
		{
			i = b->size - max_i;
			while (i-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	sort_medium(t_stack *a, t_stack *b)
{
	int				*sorted;
	unsigned int	size;
	unsigned int	i;

	if (!a || !b || a->size <= 1)
		return ;
	i = 1;
	while (i < a->size && a->data[i - 1] < a->data[i])
		i++;
	if (i >= a->size)
		return ;
	sorted = (int *)malloc(sizeof(int) * a->size);
	if (!sorted)
		return ;
	init_sorted(a, sorted, a->size);
	size = 1;
	while (size * size < a->size)
		size++;
	push_chunks(a, b, sorted, size);
	push_back(a, b);
	free(sorted);
}
