/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:00:58 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/04 10:54:48 by mdesalle         ###   ########.fr       */
/*                                                                            */ /* ************************************************************************** */

#include "../include/pipex.h"

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
