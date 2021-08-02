/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 11:17:08 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/02 16:01:29 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

int	normal(t_node *s, int return_code)
{
	free(s->path);
	free(s->file1);
	free(s->file2);
	free(s->args1);
	free(s->args2);
	exit(EXIT_SUCCESS);
	return (return_code);
}

int	error(void)
{
	exit(EXIT_FAILURE);
	return (0);
}
