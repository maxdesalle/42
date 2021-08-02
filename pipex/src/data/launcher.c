/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 15:56:45 by mdesalle          #+#    #+#             */
/*   Updated: 2021/08/02 16:10:25 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	launcher(t_node *s)
{
	pipe(s->pfd);
	s->pid = fork();
	if (s->pid == 0)
	{
		dup2(s->pfd[1], STDOUT);
		dup2(s->fd1, STDIN);
		close(s->pfd[0]);
		close(s->fd1);
		executer(s->args1);
	}
	else
	{
		dup2(s->pfd[0], STDIN);
		dup2(s->fd2, STDOUT);
		close(s->pfd[1]);
		close(s->fd2);
		executer(s->args2);
	}
}
