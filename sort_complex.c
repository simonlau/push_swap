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

#include "libft/libft.h"
#include "push_swap.h"
#include <stdlib.h>

static void	counting_pass(int *arr, unsigned int size, unsigned long divisor,
		t_radix *r)
{
	unsigned int	i;

	i = 0;
	while (i < 10)
		r->count[i++] = 0;
	i = 0;
	while (i < size)
	{
		r->count[(arr[i] / divisor) % 10]++;
		i++;
	}
	i = 1;
	while (i < 10)
	{
		r->count[i] += r->count[i - 1];
		i++;
	}
	i = size;
	while (i > 0)
	{
		i--;
		r->out[--r->count[(arr[i] / divisor) % 10]] = arr[i];
	}
	ft_memcpy(arr, r->out, size * sizeof(int));
}

static void	radix_sort(int *arr, unsigned int size, int bias, t_radix *r)
{
	int				max_val;
	unsigned int	i;
	unsigned long	divisor;

	i = 0;
	while (i < size)
		arr[i++] += bias;
	max_val = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] > max_val)
			max_val = arr[i];
		i++;
	}
	divisor = 1;
	while (divisor <= (unsigned long)max_val)
	{
		counting_pass(arr, size, divisor, r);
		divisor *= 10;
	}
	i = 0;
	while (i < size)
		arr[i++] -= bias;
}

static void	place_sorted(t_stack *a, t_stack *b, const int *sorted,
		unsigned int size)
{
	unsigned int	i;
	unsigned int	idx;

	i = 0;
	while (i < size)
	{
		idx = 0;
		while (idx < a->size && a->data[idx] != sorted[i])
			idx++;
		if (idx == a->size)
			return ;
		while (a->data[0] != sorted[i])
			rra(a);
		pb(a, b);
		i++;
	}
	while (b->size)
		pa(a, b);
}

static int	init_array(t_stack *a, int *arr, unsigned int size)
{
	int				min_val;
	unsigned int	i;

	min_val = a->data[0];
	i = 0;
	while (i < size)
	{
		arr[i] = a->data[i];
		if (a->data[i] < min_val)
			min_val = a->data[i];
		i++;
	}
	return (min_val);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int				*sorted;
	int				bias;
	t_radix			r;
	unsigned int	size;

	if (!a || a->size <= 1)
		return ;
	size = a->size;
	sorted = (int *)malloc(sizeof(int) * size);
	r.count = (int *)malloc(sizeof(int) * 10);
	r.out = (int *)malloc(sizeof(int) * size);
	if (!sorted || !r.count || !r.out)
	{
		free(sorted);
		free(r.count);
		free(r.out);
		return ;
	}
	bias = -init_array(a, sorted, size);
	radix_sort(sorted, size, bias, &r);
	place_sorted(a, b, sorted, size);
	free(sorted);
	free(r.count);
	free(r.out);
}
