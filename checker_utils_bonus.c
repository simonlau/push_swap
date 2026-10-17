/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

int	read_op_line(char *buf, unsigned int size)
{
	unsigned int	i;
	int				ret;
	char			c;

	i = 0;
	while (i < size - 1)
	{
		ret = read(0, &c, 1);
		if (ret <= 0)
			break ;
		buf[i] = c;
		i++;
		if (c == '\n')
			break ;
	}
	buf[i] = '\0';
	if (i > 0 && buf[i - 1] == '\n')
		buf[i - 1] = '\0';
	if (i == 0 && ret <= 0)
		return (0);
	return (1);
}

int	is_sorted_stack(t_stack *a)
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

int	apply_op_swap(t_stack *a, t_stack *b, const char *op)
{
	(void)b;
	if (ft_strncmp(op, "sa", 3) == 0)
		swap_top(a);
	else if (ft_strncmp(op, "sb", 3) == 0)
		swap_top(b);
	else if (ft_strncmp(op, "ss", 3) == 0)
	{
		swap_top(a);
		swap_top(b);
	}
	else
		return (0);
	return (1);
}

int	apply_op_push(t_stack *a, t_stack *b, const char *op)
{
	if (ft_strncmp(op, "pa", 3) == 0)
		stack_push(a, b);
	else if (ft_strncmp(op, "pb", 3) == 0)
		stack_push(b, a);
	else
		return (0);
	return (1);
}

int	apply_op_rotate(t_stack *a, t_stack *b, const char *op)
{
	if (ft_strncmp(op, "ra", 3) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb", 3) == 0)
		rotate(b);
	else if (ft_strncmp(op, "rr", 3) == 0)
	{
		rotate(a);
		rotate(b);
	}
	else if (ft_strncmp(op, "rra", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		reverse_rotate(b);
	else if (ft_strncmp(op, "rrr", 4) == 0)
	{
		reverse_rotate(a);
		reverse_rotate(b);
	}
	else
		return (0);
	return (1);
}
