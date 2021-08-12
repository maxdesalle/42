/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/12 14:35:21 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define FOUR_ARG 5
# define FIVE_ARG 6

# define LEFT_FORK 0
# define RIGHT_FORK 1
# define IS_EATING 2
# define IS_SLEEPING 3
# define IS_THINKING 4

typedef struct s_conf
{
	int		len;
	int		td;
	int		te;
	int		ts;
	int		ee;
	long	st;
	pthread_mutex_t	wri;
}				t_conf;

typedef struct s_phil
{
	int				id;
	pthread_t		pid;
	pthread_mutex_t	*lf;
	pthread_mutex_t	*rf;
}				t_phil;

typedef struct s_node
{
	struct s_phil	*p;
	struct s_conf	*c;
	struct s_node	*next;
	struct s_node	*prev;
}				t_node;

/* data/init.c */
int		init(t_node **h, int argc, char **argv);

/* data/linker.c */
int		linker(t_node **h, t_node **n);

/* data/time.c */
long	wtii(void);

/* data/list.c */
int		mutinit(t_node *n);
int		assign(t_node *n, t_conf *c, int i);
t_node	*create(void);

/* data/check.c */
int		valcheck(int argc, char **argv);

/* thread/threader.c */
int		threader(t_node *h);

/* thread/actions.c */
int		actionator(t_node *n);

/* thread/status.c */
int		status(t_node *n, int option);

/* misc/return.c */
int		normal(t_node *h);
int		error(t_node *h);
int		errempty(void);

/* utilities/ft_atoi.c */
int		is_empty(char c);
int		is_sign(char c);
int		is_num(char c);
int		ft_atoi(char *str);

/* utilities/ft_putnbr.c */
void	ft_putnbr(long n);

/* utilities/ft_putchar.c */
void	ft_putchar(char c);

#endif
