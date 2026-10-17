/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_simple.c                                      :+:      :+:    :+   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/15 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_stack *a)
{
	if (a->data[0] > a->data[1] && a->data[1] > a->data[2])
	{
		sa(a);
		rra(a);
	}
	else if (a->data[0] > a->data[1] && a->data[1] < a->data[2])
	{
		if (a->data[0] > a->data[2])
			ra(a);
		else
			sa(a);
	}
	else if (a->data[0] < a->data[1] && a->data[1] > a->data[2])
	{
		if (a->data[0] > a->data[2])
			rra(a);
		else
		{
			rra(a);
			sa(a);
		}
	}
}

static unsigned int	find_min_index(t_stack *a)
{
	unsigned int	i;
	unsigned int	min_index;

	i = 1;
	min_index = 0;
	while (i < a->size)
	{
		if (a->data[i] < a->data[min_index])
			min_index = i;
		i++;
	}
	return (min_index);
}

static void	extract_min(t_stack *a, t_stack *b)
{
	unsigned int	min_index;
	unsigned int	i;

	min_index = find_min_index(a);
	if (min_index <= a->size / 2)
	{
		i = 0;
		while (i < min_index)
		{
			ra(a);
			i++;
		}
	}
	else
	{
		i = min_index;
		while (i < a->size)
		{
			rra(a);
			i++;
		}
	}
	pb(a, b);
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

void	sort_simple(t_stack *a, t_stack *b)
{
	if (!a || a->size <= 1 || is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->data[0] > a->data[1])
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	extract_min(a, b);
	sort_simple(a, b);
	pa(a, b);
}
