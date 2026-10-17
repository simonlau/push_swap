/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
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

static unsigned int	checker_capacity(int argc)
{
	if (argc > 1)
		return ((unsigned int)(argc - 1));
	return (1u);
}

static int	build_checker_stacks(int argc, t_stack **a, t_stack **b)
{
	*a = stack_init(checker_capacity(argc));
	*b = stack_init(checker_capacity(argc));
	if (!*a || !*b)
	{
		stack_free(*a);
		stack_free(*b);
		return (0);
	}
	return (1);
}

static int	read_and_apply_ops(t_stack *a, t_stack *b)
{
	char		line[16];
	int			ret;

	ret = read_op_line(line, sizeof(line));
	while (ret == 1)
	{
		if (line[0] != '\0'
			&& apply_op_swap(a, b, line) == 0
			&& apply_op_push(a, b, line) == 0
			&& apply_op_rotate(a, b, line) == 0)
			return (0);
		ret = read_op_line(line, sizeof(line));
	}
	return (1);
}

static void	print_verdict(t_stack *a, t_stack *b)
{
	if (is_sorted_stack(a) && b->size == 0)
		ft_putstr_fd("OK\n", STDOUT_FILENO);
	else
		ft_putstr_fd("KO\n", STDOUT_FILENO);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (!build_checker_stacks(argc, &a, &b))
		return (1);
	if (argc > 1 && parse_args(argc, argv, a) != 0)
	{
		stack_free(a);
		stack_free(b);
		return (1);
	}
	if (read_and_apply_ops(a, b) == 0)
	{
		ft_putstr_fd("Error\n", STDERR_FILENO);
		stack_free(a);
		stack_free(b);
		return (1);
	}
	print_verdict(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
