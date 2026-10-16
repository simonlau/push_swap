/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/16 23:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"
#include <limits.h>

static int	has_duplicate(t_stack *a, int value)
{
	unsigned int	i;

	i = 0;
	while (i < a->size)
	{
		if (a->data[i] == value)
			return (1);
		i++;
	}
	return (0);
}

static int	parse_one(const char *str, int *out)
{
	long long	value;
	int			sign;
	int			i;

	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (1);
	value = 0;
	while (ft_isdigit(str[i]))
	{
		value = value * 10 + (str[i] - '0');
		i++;
	}
	value *= sign;
	if (value < INT_MIN || value > INT_MAX)
		return (1);
	*out = (int)value;
	return (0);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int		i;
	int		value;

	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (parse_one(argv[i], &value))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		if (has_duplicate(a, value))
		{
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		stack_append(a, value);
		i++;
	}
	return (0);
}
