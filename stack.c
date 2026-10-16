/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/16 21:30:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_stack	*stack_init(unsigned int capacity)
{
	t_stack			*s;
	unsigned int	real_cap;

	s = (t_stack *)malloc(sizeof(t_stack));
	if (!s)
		return (NULL);
	real_cap = capacity;
	if (real_cap == 0)
		real_cap = 1;
	s->data = (int *)malloc(sizeof(int) * real_cap);
	if (!s->data)
	{
		free(s);
		return (NULL);
	}
	s->size = 0;
	s->capacity = real_cap;
	return (s);
}

void	stack_push(t_stack *s, int value)
{
	if (!s)
		return ;
	if (s->size >= s->capacity)
		return ;
	s->data[s->size] = value;
	s->size++;
}

void	stack_free(t_stack *s)
{
	if (!s)
		return ;
	free(s->data);
	free(s);
}

int	stack_is_sorted(t_stack *s)
{
	unsigned int	i;

	if (!s || s->size <= 1)
		return (1);
	i = 0;
	while (i < s->size - 1)
	{
		if (s->data[i] > s->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
