/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/07/12 13:49:37 by mdesalle         ###   ########.fr       */
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
void	multi_save(t_node **head, int argc, char **argv);

/* list/one_save.c */
int		one_save(t_node **a_head, char **argv);

/* list/create.c */
int		d_check(t_node *a_head, int value, int i);
void	create(t_node **a_head, int value);

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

/* algorithm/utils.c */
int		is_sorted(t_node **head);

/* algorithm/five_or_less.c */
void	five_or_less(t_node **a_head, t_node **b_head);

/* conditions/next.c */
int		next_bigger(t_node *head);
int		next_smaller(t_node *head);

/* conditions/prev.c */
int		prev_bigger(t_node *head);
int		prev_smaller(t_node *head);

/* moves/.c */
void	sa(t_node **a_head);
void	sb(t_node **b_head);
void	ss(t_node **a_head, t_node **b_head);
void	ra(t_node **a_head);
void	rb(t_node **b_head);
void	rr(t_node **a_head, t_node **b_head);
void	rra(t_node **a_head);
void	rrb(t_node **b_head);
void	rrr(t_node **a_head, t_node **b_head);
void	pa(t_node **a_head, t_node **b_head);
void	pb(t_node **a_head, t_node **b_head);

#endif
