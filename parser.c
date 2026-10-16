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

static int	report_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (1);
}

static int	is_valid_integer(const char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (ft_isdigit(str[i]))
		i++;
	return (str[i] == '\0');
}

static int	magnitude_overflows(const char *digits, int is_negative)
{
	int	len;

	len = 0;
	while (digits[len])
		len++;
	if (len > 10)
		return (1);
	if (len < 10)
		return (0);
	if (is_negative)
		return (ft_strncmp(digits, "2147483648", 10) > 0);
	return (ft_strncmp(digits, "2147483647", 10) > 0);
}

int	parse_args(int argc, char **argv, t_stack *a)
{
	int			i;
	int			value;
	const char	*digits;

	if (argc <= 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		if (!is_valid_integer(argv[i]))
			return (report_error());
		if (argv[i][0] == '-' || argv[i][0] == '+')
			digits = argv[i] + 1;
		else
			digits = argv[i];
		if (magnitude_overflows(digits, argv[i][0] == '-'))
			return (report_error());
		value = ft_atoi(argv[i]);
		if (has_duplicate(a, value))
			return (report_error());
		stack_append(a, value);
		i++;
	}
	return (0);
}
