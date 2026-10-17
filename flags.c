/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static int	is_flag(const char *arg)
{
	return (arg != NULL && arg[0] == '-' && arg[1] == '-');
}

static int	flag_eq(const char *arg, const char *name)
{
	size_t	len;

	len = ft_strlen(name);
	return (ft_strncmp(arg, name, len) == 0 && arg[len] == '\0');
}

static int	parse_flag(const char *arg, int *strategy, int *bench)
{
	if (flag_eq(arg, "--simple"))
		*strategy = 0;
	else if (flag_eq(arg, "--medium"))
		*strategy = 1;
	else if (flag_eq(arg, "--complex"))
		*strategy = 2;
	else if (flag_eq(arg, "--adaptive"))
		*strategy = 3;
	else if (flag_eq(arg, "--bench"))
		*bench = 1;
	else
		return (0);
	return (1);
}

t_flags	parse_flags(int argc, char **argv)
{
	t_flags	f;
	int		i;
	int		j;

	f.strategy = 3;
	f.bench = 0;
	i = 1;
	j = 1;
	while (i < argc)
	{
		if (is_flag(argv[i]) && !parse_flag(argv[i], &f.strategy, &f.bench))
		{
			f.strategy = -1;
			return (f);
		}
		else if (!is_flag(argv[i]))
		{
			argv[j] = argv[i];
			j++;
		}
		i++;
	}
	f.new_argc = j;
	return (f);
}
