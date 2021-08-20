/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:33:07 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/20 10:41:04 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	is_thinking(t_node *n)
{
	pthread_mutex_lock(&n->c->wri);
	status(n, IS_THINKING);
	pthread_mutex_unlock(&n->c->wri);
	return (1);
}

static int	is_sleeping(t_node *n)
{
	pthread_mutex_lock(&n->c->wri);
	status(n, IS_SLEEPING);
	pthread_mutex_unlock(&n->c->wri);
	sleeper(n, n->c->ts);
	return (1);
}

static int	is_eating(t_node *n)
{
	pthread_mutex_lock(n->p->lf);
	pthread_mutex_lock(&n->c->wri);
	status(n, LEFT_FORK);
	pthread_mutex_unlock(&n->c->wri);
	pthread_mutex_lock(&n->p->rf);
	pthread_mutex_lock(&n->c->wri);
	status(n, RIGHT_FORK);
	pthread_mutex_unlock(&n->c->wri);
	pthread_mutex_lock(&n->c->eat);
	n->p->ts = wtii();
	pthread_mutex_unlock(&n->c->eat);
	pthread_mutex_lock(&n->c->wri);
	status(n, IS_EATING);
	pthread_mutex_unlock(&n->c->wri);
	pthread_mutex_lock(&n->c->stex);
	if (n->c->ee)
		n->c->ct += 1;
	pthread_mutex_unlock(&n->c->stex);
	sleeper(n, n->c->te);
	pthread_mutex_unlock(n->p->lf);
	pthread_mutex_unlock(&n->p->rf);
	return (1);
}

int	actionator(t_node *n)
{
	if (stopper(n) && !death_check(n))
		is_eating(n);
	if (stopper(n) && !death_check(n))
		is_sleeping(n);
	if (stopper(n) && !death_check(n))
		is_thinking(n);
	return (1);
}
