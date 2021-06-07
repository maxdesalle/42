/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/07 19:45:05 by mdesalle         ###   ########.fr       */
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

# define ZERO_ARGUMENT 1
# define TWO_ARGUMENTS 3

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}				t_node;

/* list.c */
t_node	*save(int argc, char **argv);

/* atoi.c */
int		is_empty(char c);
int		is_sign(char c);
int		is_num(char c);
int		ft_atoi(char *str);

/* return.c */
void	instruct(int option);
int		normal(int return_code);
int		error(void);

/* sort.c */
void	sort(t_node *head, int argc);

/* utils.c */
void	ft_swap(int *a, int *b);

#endif
