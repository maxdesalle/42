/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/09 15:32:34 by maxdesall        ###   ########.fr       */
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

typedef struct s_conf
{
	int		len;
	int		td;
	int		te;
	int		ts;
	int		ee;
	long	st;
}				t_conf;

typedef struct s_phil
{
	int				id;
	pthread_t		pid;
	pthread_mutex_t	*rf;
	pthread_mutex_t	*lf;
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

/* data/check.c */
int		valcheck(int argc, char **argv);

/* misc/return.c */
int		errtoi(void);
int		error(void);

/* utilities/ft_atoi.c */
int		is_empty(char c);
int		is_sign(char c);
int		is_num(char c);
int		ft_atoi(char *str);

#endif
