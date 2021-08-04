/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:12:36 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/04 11:29:36 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

/* executes the command */
/* returns the error function is something went wrong */

int	executer(t_node *s, char **args)
{
	char	**envp;

	envp = NULL;
	if (execve(args[0], args, envp) == -1)
		return (error(s));
	return (0);
}

/* tries out to access a path for the executable, frees after each attempt */
/* to avoid memory leaks */

char	*command(char **path, char *cmd)
{
	int		i;
	char	*str;
	char	**tab;

	i = 0;
	while (path[i])
	{
		str = ft_strjoin(path[i], "/");
		tab = ft_split(cmd, ' ');
		str = ft_strjoin(str, tab[0]);
		if (access(str, 0) == 0)
			return (str);
		free(str);
		str = NULL;
		i += 1;
	}
	return (NULL);
}
