/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* strategy values: 0 = simple, 1 = medium, 2 = complex, 3 = adaptive */
void	select_strategy(t_stack *a, t_stack *b, int strategy)
{
	if (!a || !b)
		return ;
	if (strategy == 0)
		sort_simple(a, b);
	else if (strategy == 1)
		sort_medium(a, b);
	else if (strategy == 2)
		sort_complex(a, b);
	else
		sort_adaptive(a, b);
}
