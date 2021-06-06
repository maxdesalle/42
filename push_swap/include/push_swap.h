/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/06 13:55:35 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

typedef struct s_node
{
	int	value;
	struct s_node *previous;
	struct s_node *next;
}		t_node;

/* list.c */
t_node	*save(int argc, char **argv);

/* utils.c */
int	is_empty(char c);
int	is_sign(char c);
int	is_num(char c);
int	ft_atoi(char *str);
int	error(void);

#endif
