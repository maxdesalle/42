/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 14:33:07 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/11 14:44:36 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	is_thinking(t_node *n)
{
	pthread_mutex_lock(&n->p->wri);
	status(IS_THINKING);
	pthread_mutex_unlock(&n->p->wri);
	return (1);
}

static int	is_sleeping(t_node *n)
{
	pthread_mutex_lock(&n->p->wri);
	status(IS_SLEEPING);
	pthread_mutex_unlock(&n->p->wri);
	usleep(n->c->ts * 1000);
	return (1);
}

static int	is_eating(t_node *n)
{
	pthread_mutex_lock(&n->p->lf);
	pthread_mutex_lock(&n->p->wri);
	status(LEFT_FORK);
	pthread_mutex_unlock(&n->p->wri);
	pthread_mutex_lock(&n->p->rf);
	pthread_mutex_lock(&n->p->wri);
	status(RIGHT_FORK);
	status(IS_EATING);
	pthread_mutex_unlock(&n->p->wri);
	pthread_mutex_unlock(&n->p->lf);
	pthread_mutex_unlock(&n->p->rf);
	usleep(n->c->te * 1000);
	return (1);
}

int	actionator(t_node *n)
{
	is_eating(n);
	is_sleeping(n);
	is_thinking(n);
	return (1);
}
