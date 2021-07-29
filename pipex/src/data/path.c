/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 10:54:21 by maxdesall         #+#    #+#             */
/*   Updated: 2021/07/29 11:23:26 by maxdesall        ###   ########.fr       */
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
	return (tab);
}
