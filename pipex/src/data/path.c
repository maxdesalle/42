/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:54:21 by maxdesall         #+#    #+#             */
/*   Updated: 2021/07/30 11:51:59 by maxdesall        ###   ########.fr       */
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

int	filer(char **file1, char **argv)
{
	int	fd;

	if (access(argv[1], 0) != 0)
		return (error());
	fd = open(argv[1], O_RDWR);
	if (fd < 0 || fd > OPEN_MAX)
		return (error());
	*file1 = ft_strdup(argv[2]);
	*file1 = ft_strjoin(*file1, " ");
	*file1 = ft_strjoin(*file1, argv[1]);
	return (0);
}
