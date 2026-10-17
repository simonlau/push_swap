/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_count.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*op_counter(void)
{
	static int	c[OP_COUNT] = {0};

	return (c);
}

void	op_count_reset(void)
{
	int		*c;
	int		i;

	c = op_counter();
	i = 0;
	while (i < OP_COUNT)
	{
		c[i] = 0;
		i++;
	}
}

void	op_count_inc(t_op op)
{
	int		*c;

	c = op_counter();
	if (op >= 0 && op < OP_COUNT)
		c[op]++;
}

int	op_count_get(t_op op)
{
	int		*c;

	c = op_counter();
	if (op >= 0 && op < OP_COUNT)
		return (c[op]);
	return (0);
}

int	op_count_total(void)
{
	int		*c;
	int		total;
	int		i;

	c = op_counter();
	total = 0;
	i = 0;
	while (i < OP_COUNT)
	{
		total += c[i];
		i++;
	}
	return (total);
}
