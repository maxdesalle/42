/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:54:21 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/03 16:32:58 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	*finder(char **envp)
{
	int		i;
	char	*path;

	i = 0;
	path = NULL;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], "PATH", 4))
		{
			path = envp[i];
			break ;
		}
		i += 1;
	}
	return (path);
}

char	**path_finder(char **envp)
{
	char	*path;
	char	**tab;

	path = finder(envp);
	tab = ft_split(path, ':');
	if (!tab)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

int	filer1(int *fd, char **file, char *argv1, char *argv2)
{
	*fd = open(argv1, O_RDWR);
	if (*fd < 0 || *fd > OPEN_MAX)
	{
		close(*fd);
		return (0);
	}
	*file = ft_strdup(argv2);
	return (1);
}

int	filer2(int *fd, char **file, char *argv1, char *argv2)
{
	*fd = open(argv1, O_RDWR | O_TRUNC | O_CREAT, 0666);
	if (*fd < 0 || *fd > OPEN_MAX)
	{
		close(*fd);
		return (0);
	}
	*file = ft_strdup(argv2);
	return (1);
}

int	saver(t_node *s, char **argv, char **envp)
{
	s->path = path_finder(envp);
	if (!s->path)
		return (0);
	if (!filer1(&s->fd1, &s->file1, argv[1], argv[2]))
		return (0);
	s->args1 = ft_split(s->file1, ' ');
	if (!s->args1)
		return (0);
	s->args1[0] = command(s->path, s->file1);
	if (!s->args1[0])
		return (0);
	if (!filer2(&s->fd2, &s->file2, argv[4], argv[3]))
		return (0);
	s->args2 = ft_split(s->file2, ' ');
	if (!s->args2)
		return (0);
	s->args2[0] = command(s->path, s->file2);
	if (!s->args2[0])
		return (0);
	return (1);
}
