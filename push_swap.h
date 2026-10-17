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
typedef struct s_flags
{
	int				strategy;
	int				bench;
	int				new_argc;
}					t_flags;

typedef enum e_op
{
	OP_SA,
	OP_SB,
	OP_SS,
	OP_PA,
	OP_PB,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_COUNT,
}					t_op;

void				op_count_reset(void);
void				op_count_inc(t_op op);
int					op_count_get(t_op op);
int					op_count_total(void);

void				swap_top(t_stack *s);
void				stack_push(t_stack *dst, t_stack *src);
void				rotate(t_stack *s);
void				reverse_rotate(t_stack *s);

int					read_op_line(char *buf, unsigned int size);
int					apply_op_swap(t_stack *a, t_stack *b, const char *op);
int					apply_op_push(t_stack *a, t_stack *b, const char *op);
int					apply_op_rotate(t_stack *a, t_stack *b, const char *op);
int					is_sorted_stack(t_stack *a);

t_flags				parse_flags(int argc, char **argv);
void				print_bench(int strategy, double disorder, int fd);

#endif
