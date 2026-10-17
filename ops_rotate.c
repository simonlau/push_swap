/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
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

void	rotate(t_stack *s)
{
	int				tmp;
	unsigned int	i;

	if (!s || s->size < 2)
		return ;
	tmp = s->data[0];
	i = 0;
	while (i < s->size - 1)
	{
		s->data[i] = s->data[i + 1];
		i++;
	}
	s->data[s->size - 1] = tmp;
}

void	ra(t_stack *a)
{
	rotate(a);
	ft_putstr_fd("ra\n", STDOUT_FILENO);
	op_count_inc(OP_RA);
}

void	rb(t_stack *b)
{
	rotate(b);
	ft_putstr_fd("rb\n", STDOUT_FILENO);
	op_count_inc(OP_RB);
}

void	rr(t_stack *a, t_stack *b)
{
	rotate(a);
	rotate(b);
	ft_putstr_fd("rr\n", STDOUT_FILENO);
	op_count_inc(OP_RR);
}
