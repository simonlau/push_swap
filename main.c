/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	build_stacks(int argc, char **argv, t_stack **a, t_stack **b)
{
	*a = stack_init((unsigned int)argc);
	*b = stack_init((unsigned int)argc);
	if (!*a || !*b)
	{
		stack_free(*a);
		stack_free(*b);
		return (1);
	}
	if (argc > 1 && parse_args(argc, argv, *a) != 0)
	{
		stack_free(*a);
		stack_free(*b);
		return (1);
	}
	return (0);
}

static void	run_strategy(t_stack *a, t_stack *b)
{
	double	disorder;
	int		strategy;

	disorder = compute_disorder(a);
	if (disorder < 0.2)
		strategy = 0;
	else if (disorder < 0.5)
		strategy = 1;
	else
		strategy = 2;
	select_strategy(a, b, strategy);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	if (build_stacks(argc, argv, &a, &b) != 0)
		return (1);
	if (a->size <= 1)
	{
		stack_free(a);
		stack_free(b);
		return (0);
	}
	run_strategy(a, b);
	stack_free(a);
	stack_free(b);
	return (0);
}
