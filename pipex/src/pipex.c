/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */ /*   Created: 2021/07/28 17:00:58 by maxdesall         #+#    #+#             */
/*   Updated: 2021/07/29 18:48:28 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_node	s;

	if (argc != 2)
		return (error());
	s.path = path_finder(envp);
	if (!s.path)
		return (error());
	s.args1 = ft_split(argv[1], ' ');
	s.args1[0] = command(s.path, argv[1]);
	if (!s.args1[0])
		return (error());
	executer(s.args1);
	return (0);
}
