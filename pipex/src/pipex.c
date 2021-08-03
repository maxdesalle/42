/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:00:58 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/03 07:46:16 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	s;

	if (argc != FOUR_ARG)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
		return (0);
	}
	if (!saver(&s, argv, envp))
	{
		write(1, "Error\n", 6);
		return (error(&s));
	}
	if (!launcher(&s))
	{
		write(1, "Error\n", 6);
		return (error(&s));
	}
	return (normal(&s, 0));
}
