/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
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

void	swap_top(t_stack *s)
{
	int	tmp;

	if (!s || s->size < 2)
		return ;
	tmp = s->data[0];
	s->data[0] = s->data[1];
	s->data[1] = tmp;
}

void	sa(t_stack *a)
{
	swap_top(a);
	ft_putstr_fd("sa\n", STDOUT_FILENO);
	op_count_inc(OP_SA);
}

void	sb(t_stack *b)
{
	swap_top(b);
	ft_putstr_fd("sb\n", STDOUT_FILENO);
	op_count_inc(OP_SB);
}

void	ss(t_stack *a, t_stack *b)
{
	swap_top(a);
	swap_top(b);
	ft_putstr_fd("ss\n", STDOUT_FILENO);
	op_count_inc(OP_SS);
}
