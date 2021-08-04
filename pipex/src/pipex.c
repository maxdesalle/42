/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:00:58 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/04 11:18:56 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

/* initiates the struct, calls the required functions and returns an error if */
/* an error code is returned by one of the processes */

int	main(int argc, char **argv, char **envp)
{
	t_node	s;

	init(&s);
	if (argc != FOUR_ARG)
		return (error(&s));
	if (!saver(&s, argv, envp))
		return (error(&s));
	if (!launcher(&s))
		return (error(&s));
	return (normal(&s, 0));
}
