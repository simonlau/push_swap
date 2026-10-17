/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_adaptive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/17 12:00:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* disorder thresholds: < 0.2 simple, < 0.5 medium, >= 0.5 complex */
void	sort_adaptive(t_stack *a, t_stack *b)
{
	double	disorder;

	if (!a || !b || a->size <= 1)
		return ;
	disorder = compute_disorder(a);
	if (disorder < 0.2)
		sort_simple(a, b);
	else if (disorder < 0.5)
		sort_medium(a, b);
	else
		sort_complex(a, b);
}
