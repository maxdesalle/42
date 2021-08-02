/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:54:21 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/02 16:12:23 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	*finder(char **envp)
{ int		i;
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
		error();
		return (NULL);
	}
	return (tab);
}

int	filer1(int *fd, char **file, char *argv1, char *argv2)
{
	*fd = open(argv1, O_RDWR);
	if (*fd < 0 || *fd > OPEN_MAX)
		return (error());
	*file = ft_strdup(argv2);
	return (0);
}

int	filer2(int *fd, char **file, char *argv1, char *argv2)
{
	*fd = open(argv1, O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (*fd < 0 || *fd > OPEN_MAX)
		return (error());
	*file = ft_strdup(argv2);
	return (0);
}

void	saver(t_node *s, char **argv, char **envp)
{
	s->path = path_finder(envp);
	filer1(&s->fd1, &s->file1, argv[1], argv[2]);
	s->args1 = ft_split(s->file1, ' ');
	s->args1[0] = command(s->path, s->file1);
	filer2(&s->fd2, &s->file2, argv[4], argv[3]);
	s->args2 = ft_split(s->file2, ' ');
	s->args2[0] = command(s->path, s->file2);
}
