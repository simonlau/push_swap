/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <unistd.h>

static void	print_percent(double d, int fd)
{
	int		v;
	int		ip;
	int		dp;

	v = (int)(d * 10000.0 + 0.5);
	ip = v / 100;
	dp = v % 100;
	ft_putnbr_fd(ip, fd);
	ft_putchar_fd('.', fd);
	if (dp < 10)
		ft_putchar_fd('0', fd);
	ft_putnbr_fd(dp, fd);
	ft_putstr_fd("%", fd);
}

static void	print_op_count(t_op op, int fd)
{
	ft_putnbr_fd(op_count_get(op), fd);
	ft_putchar_fd('\n', fd);
}

static void	print_counts(int fd)
{
	ft_putstr_fd("sa: ", fd);
	print_op_count(OP_SA, fd);
	ft_putstr_fd("sb: ", fd);
	print_op_count(OP_SB, fd);
	ft_putstr_fd("ss: ", fd);
	print_op_count(OP_SS, fd);
	ft_putstr_fd("pa: ", fd);
	print_op_count(OP_PA, fd);
	ft_putstr_fd("pb: ", fd);
	print_op_count(OP_PB, fd);
	ft_putstr_fd("ra: ", fd);
	print_op_count(OP_RA, fd);
	ft_putstr_fd("rb: ", fd);
	print_op_count(OP_RB, fd);
	ft_putstr_fd("rr: ", fd);
	print_op_count(OP_RR, fd);
	ft_putstr_fd("rra: ", fd);
	print_op_count(OP_RRA, fd);
	ft_putstr_fd("rrb: ", fd);
	print_op_count(OP_RRB, fd);
	ft_putstr_fd("rrr: ", fd);
	print_op_count(OP_RRR, fd);
}

void	print_bench(int strategy, double disorder, int fd)
{
	ft_putstr_fd("disorder: ", fd);
	print_percent(disorder, fd);
	ft_putchar_fd('\n', fd);
	ft_putstr_fd("strategy: ", fd);
	if (strategy == 0)
		ft_putstr_fd("simple", fd);
	else if (strategy == 1)
		ft_putstr_fd("medium", fd);
	else if (strategy == 2)
		ft_putstr_fd("complex", fd);
	else
		ft_putstr_fd("adaptive", fd);
	ft_putstr_fd(" (", fd);
	if (strategy == 0)
		ft_putstr_fd("O(n^2)", fd);
	else if (strategy == 1)
		ft_putstr_fd("O(n sqrt n)", fd);
	else
		ft_putstr_fd("O(n log n)", fd);
	ft_putstr_fd(")\noperations: ", fd);
	ft_putnbr_fd(op_count_total(), fd);
	ft_putchar_fd('\n', fd);
	print_counts(fd);
}
