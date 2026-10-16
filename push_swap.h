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
void				stack_push(t_stack *s, int value);
void				stack_free(t_stack *s);
int					stack_is_sorted(t_stack *s);
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

int					checker_parse_args(int argc, char **argv, t_stack *a);

#endif
