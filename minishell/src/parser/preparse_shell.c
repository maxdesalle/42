/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparse_shell.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 17:21:53 by mlazzare          #+#    #+#             */
/*   Updated: 2021/09/30 12:12:48 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	builtin_cmd(char *cmd)
{
	if (!cmd)
		return (0);
	return (!ft_strcmp("exit", cmd) || !ft_strcmp("export", cmd)
		|| !ft_strcmp("unset", cmd) || !ft_strcmp("cd", cmd));
}

int	not_executable_cmd(t_shell *s, char *cmd, int j)
{
	char		*exec;
	struct stat	sb;

	if (!cmd || (stat(cmd, &sb) == 0 && sb.st_mode & S_IXUSR))
		return (0);
	if (!s->path)
	{
		bash_error_cmd_not_found(s, cmd);
		return (1);
	}
	while (s->path[++j])
	{
		exec = ft_join(s->path[j], cmd);
		if (!exec)
			malloxit();
		if (stat(exec, &sb) == 0 && sb.st_mode & S_IXUSR)
		{
			free(exec);
			return (0);
		}
		free(exec);
	}
	bash_error_cmd_not_found(s, cmd);
	return (1);
}

int	not_pipeable_cmd(t_shell *s)
{
	if (heredoc_with_nocmd(s) || builtin_cmd(s->arg[0])
		|| (!s->file.stopword && not_executable_cmd(s, s->arg[0], -1)))
	{
		free_arr(s->arg);
		return (1);
	}
	return (0);
}

int	preparse_shell(t_shell *shell, char *line)
{
	reinit_shell(shell);
	shell->cmd = ft_presplit(shell, line, '|');
	if (!shell->cmd)
		return (ft_exit(shell, "Shell cmd"));
	shell->pipelen = ft_tablen(shell->cmd);
	if (shell->error_skip)
		free_arr(shell->cmd);
	free(line);
	return (0);
}
