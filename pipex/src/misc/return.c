/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:17:08 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/03 09:08:32 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	normal(t_node *s, int return_code)
{
	int	i;

	i = -1;
	while (s->path[++i])
		free(s->path[i]);
	free(s->path);
	free(s->file1);
	free(s->file2);
	i = -1;
	while (s->args1[++i])
		free(s->args1[i]);
	free(s->args1);
	i = -1;
	while (s->args2[++i])
		free(s->args2[i]);
	free(s->args2);
	exit(EXIT_SUCCESS);
	return (return_code);
}

int	error(t_node *s)
{
	exit(EXIT_FAILURE);
	return (s->pid);
}
