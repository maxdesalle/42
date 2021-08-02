/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 17:00:58 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/02 14:31:14 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	pid_t	pid;
	t_node	s;

	if (argc != FOUR_ARG)
		return (error());
	s.path = path_finder(envp);
	filer1(&s.fd1, &s.file1, argv[1], argv[2]);
	s.args1 = ft_split(s.file1, ' ');
	s.args1[0] = command(s.path, s.file1);
	filer2(&s.fd2, &s.file2, argv[4], argv[3]);
	s.args2 = ft_split(s.file2, ' ');
	s.args2[0] = command(s.path, s.file2);
	pipe(pipefd);
	pid = fork();
	if (pid == 0)
	{
		dup2(pipefd[1], STDOUT);
		dup2(s.fd1, STDIN);
		close(pipefd[0]);
		close(s.fd1);
		executer(s.args1);
	}
	else
	{
		dup2(pipefd[0], STDIN);
		dup2(s.fd2, STDOUT);
		close(pipefd[1]);
		close(s.fd2);
		executer(s.args2);
	}
	return (0);
}
