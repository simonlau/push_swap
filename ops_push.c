/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/16 21:30:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

void	stack_push(t_stack *dst, t_stack *src)
{
	int				value;
	unsigned int	i;

	if (!dst || !src || src->size == 0)
		return ;
	value = src->data[0];
	i = 0;
	while (i < src->size - 1)
	{
		src->data[i] = src->data[i + 1];
		i++;
	}
	src->size--;
	i = dst->size;
	while (i > 0)
	{
		dst->data[i] = dst->data[i - 1];
		i--;
	}
	dst->data[0] = value;
	dst->size++;
}

void	pa(t_stack *a, t_stack *b)
{
	stack_push(a, b);
	ft_putstr_fd("pa\n", STDOUT_FILENO);
	op_count_inc(OP_PA);
}

void	pb(t_stack *a, t_stack *b)
{
	stack_push(b, a);
	ft_putstr_fd("pb\n", STDOUT_FILENO);
	op_count_inc(OP_PB);
}
