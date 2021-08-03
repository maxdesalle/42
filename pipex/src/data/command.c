/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:12:36 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/03 07:18:17 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

void	executer(char **args)
{
	char	**envp;

	envp = NULL;
	if (execve(args[0], args, envp) == -1)
		perror("Error");
}

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
