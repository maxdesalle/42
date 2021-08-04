/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:17:08 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/04 11:20:48 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/* frees all the malloc'd memory, and exits using the exit status */
/* of the pid */

int	normal(t_node *s, int return_code)
{
	while (s->path[++(s->i)])
		free(s->path[s->i]);
	free(s->path);
	free(s->file1);
	free(s->file2);
	s->i = -1;
	while (s->args1[++(s->i)])
		free(s->args1[s->i]);
	free(s->args1);
	s->i = -1;
	while (s->args2[++(s->i)])
		free(s->args2[s->i]);
	free(s->args2);
	exit(s->status);
	return (return_code);
}

/* frees all the malloc'd memory, and exits using the EXIT_FAILURE macro */

int	error(t_node *s)
{
	if (s->file1)
		free(s->file1);
	if (s->file2)
		free(s->file2);
	if (s->path)
		while (s->path[++(s->i)])
			free(s->path[s->i]);
	if (s->args1)
	{
		s->i = -1;
		while (s->args1[++(s->i)])
			free(s->args1[s->i]);
		free(s->args1);
	}
	if (s->args2)
	{
		s->i = -1;
		while (s->args2[++(s->i)])
			free(s->args2[s->i]);
		free(s->args2);
	}
	write(STDERR, "Error\n", 6);
	exit(EXIT_FAILURE);
	return (0);
}
