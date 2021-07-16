/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/16 14:51:47 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SA 0
# define SB 1
# define SS 2
# define PA 3
# define PB 4
# define RA 5
# define RB 6
# define RR 7
# define RRA 8
# define RRB 9
# define RRR 10

# define ZERO_ARG 1
# define ONE_ARG 2
# define TWO_ARG 3

# define STDOUT 1
# define STDERR 2

typedef struct s_node
{
	int				value;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

/* list/multi_save.c */
int		*multi_save(t_node **head, int argc, char **argv);

/* list/one_save.c */
int		*one_save(t_node **a_head, char **argv, int *len);

/* list/create.c */
int		d_check(t_node *a_head, int value, int i);
void	create(t_node **a_head, int value);

/* list/median.c */
int		median_finder(int *list, int len);

/* utilities/atoi.c */
int		is_empty(char c);
int		is_sign(char c);
int		is_num(char c);
int		ft_atoi(char *str);

/* utilities/return.c */
void	instruct(int option);
int		normal(int return_code);
int		error(void);

/* utilities/utils.c */
int		listlen(t_node *head);
void	listprint(t_node *head);
void	is_valid(t_node *a_head);

/* algorithm/utils.c */
int		is_sorted(t_node *head);
int		place_len(t_node *head, t_node *node);

/* algorithm/calc.c */
int		place_calc(t_node *a_head, t_node *b_head);
int		inv_place_calc(t_node *a_head, t_node *b_head);
int		pcalc(t_node *a_head, t_node *b_head);
int		rotate_calc(t_node *head, int low);
int		a_swap_calc(t_node *head, t_node *node);
int		b_swap_calc(t_node *head, t_node *node);

/* algorithm/value.c */
int		highest(t_node *head);
int		lowest(t_node *head);

/* algorithm/five.c */
void	five(t_node **a_head, t_node **b_head);

/* algorithm/hundred.c */
void	hundred(t_node **a_head, t_node **b_head, int median);

/* conditions/next.c */
int		next_bigger(t_node *head);
int		next_smaller(t_node *head);

/* conditions/prev.c */
int		prev_bigger(t_node *head);
int		prev_smaller(t_node *head);

/* conditions/b.c */
int		b_bigger(t_node *a_head, t_node *b_head);
int		b_smaller(t_node *a_head, t_node *b_head);
int		b_first(t_node *a_head, t_node *b_head);
int		b_last(t_node *a_head, t_node *b_head);

/* moves/.c */
void	sa(t_node **a_head, int option);
void	sb(t_node **b_head, int option);
void	ss(t_node **a_head, t_node **b_head);
void	ra(t_node **a_head, int option);
void	rb(t_node **b_head, int option);
void	rr(t_node **a_head, t_node **b_head);
void	rra(t_node **a_head, int option);
void	rrb(t_node **b_head, int option);
void	rrr(t_node **a_head, t_node **b_head);
void	pa(t_node **a_head, t_node **b_head);
void	pb(t_node **a_head, t_node **b_head);

#endif
