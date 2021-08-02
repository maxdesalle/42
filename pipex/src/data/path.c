/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:54:21 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/02 14:31:27 by mdesalle         ###   ########.fr       */
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
	/* *file = ft_strjoin(*file, " "); */
	/* *file = ft_strjoin(*file, argv1); */
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
