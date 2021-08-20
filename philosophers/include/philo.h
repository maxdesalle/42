/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 09:36:10 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/20 10:41:18 by maxdesall        ###   ########.fr       */
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

/* multiplier to convert microseconds into milliseconds */

# define MS 1000

/* single config struct for all philosophers */

/* len: number of philosophers */
/* te: time to eat */
/* ts: time to sleep */
/* ee: number of times each philosopher must eat */
/* de: is a philosopher dead? */
/* ct: counter variable */
/* dc: mutex destroy counter */
/* ndc: normal mutex destroy counter */
/* td: time to die */
/* st: start time */
/* eat: mutex for eating timestamp function */
/* wri: mutex for status writing */
/* end: mutex for end check */
/* stex: mutex for numer of time eaten check */
/* death: mutex for death check */

typedef struct s_conf
{
	int				len;
	int				te;
	int				ts;
	int				ee;
	int				de;
	int				ct;
	long			dc;
	long			ndc;
	long			td;
	long			st;
	pthread_mutex_t	eat;
	pthread_mutex_t	wri;
	pthread_mutex_t	end;
	pthread_mutex_t	stex;
	pthread_mutex_t	death;
}				t_conf;

/* struct specific to each philosopher */

/* id: id for each philosopher */
/* ts: timestamp when last eaten */
/* pid: thread pid for each philosopher */
/* *lf: left fork pointer to mutex */
/* rf: right fork mutex */

typedef struct s_phil
{
	int				id;
	long			ts;
	pthread_t		pid;
	pthread_mutex_t	*lf;
	pthread_mutex_t	rf;
}				t_phil;

/* doubly circular linked list */

/* each philosopher has a s_phil struct */
/* all philosophers have the same c_conf struct */

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
int		sleeper(t_node *n, long ms);
long	wtii(void);

/* data/list.c */
int		forker(t_node *n);
int		mutinit(t_node *n);
int		assign(t_node *n, t_conf *c, int i);
t_node	*create(void);

/* data/check.c */
int		valcheck(int argc, char **argv);

/* thread/threader.c */
int		stopper(t_node *n);
int		threader(t_node *h);

/* thread/actions.c */
int		actionator(t_node *n);

/* thread/threadkill.c */
int		death_check(t_node *n);
int		threadkill(t_node *h);

/* thread/status.c */
int		status(t_node *n, int option);
int		death(t_node *n);

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
