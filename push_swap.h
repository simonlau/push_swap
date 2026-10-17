/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slau <slau@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 12:00:00 by slau             #+#    #+#             */
/*   Updated: 2026/10/16 21:30:00 by slau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack
{
	int				*data;
	unsigned int	size;
	unsigned int	capacity;
}					t_stack;

typedef struct s_radix
{
	int				*count;
	int				*out;
}					t_radix;

t_stack				*stack_init(unsigned int capacity);
void				stack_append(t_stack *s, int value);
void				stack_free(t_stack *s);
int					parse_args(int argc, char **argv, t_stack *a);

void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);

void				sort_simple(t_stack *a, t_stack *b);
void				sort_medium(t_stack *a, t_stack *b);
void				sort_complex(t_stack *a, t_stack *b);
void				sort_adaptive(t_stack *a, t_stack *b);
void				select_strategy(t_stack *a, t_stack *b, int strategy);

int					ft_abs(int n);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
double				compute_disorder(t_stack *a);

int					checker_parse_args(int argc, char **argv, t_stack *a);

#endif
