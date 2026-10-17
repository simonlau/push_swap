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
#include "libft/libft.h"
#include <unistd.h>

static int	build_stacks(int new_argc, t_stack **a, t_stack **b)
{
	unsigned int	cap;

	if (new_argc > 0)
		cap = (unsigned int)new_argc;
	else
		cap = 1;
	*a = stack_init(cap);
	*b = stack_init(cap);
	if (!*a || !*b)
	{
		stack_free(*a);
		stack_free(*b);
		return (0);
	}
	return (1);
}

static void	run_strategy(t_stack *a, t_stack *b, int strategy)
{
	if (a->size <= 1)
		return ;
	op_count_reset();
	select_strategy(a, b, strategy);
}

int	main(int argc, char **argv)
{
	t_flags		f;
	t_stack		*a;
	t_stack		*b;
	double		disorder;

	f = parse_flags(argc, argv);
	if (f.strategy < 0)
		return (1);
	if (!build_stacks(f.new_argc, &a, &b))
		return (1);
	if (f.new_argc > 1 && parse_args(f.new_argc, argv, a) != 0)
	{
		stack_free(a);
		stack_free(b);
		return (1);
	}
	disorder = compute_disorder(a);
	run_strategy(a, b, f.strategy);
	if (f.bench)
		print_bench(f.strategy, disorder, STDERR_FILENO);
	stack_free(a);
	stack_free(b);
	return (0);
}
