/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shell.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 15:42:58 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/29 10:21:37 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static char	**get_paths(char **ep)
{
	char	**ret;
	char	*env;
	int		i;

	i = -1;
	while (ep[++i])
	{
		if (!ft_strncmp(ep[i], "PATH=", PATH))
		{
			env = ft_substr(ep[i], START - 1, ft_strlen(ep[i]));
			if (!env)
				exit(EXIT_FAILURE);
			else if (ft_strlen(env) == 0)
				return (NULL);
			ret = ft_splitpath(env, ':');
			if (!ret)
			{
				free(env);
				exit(EXIT_FAILURE);
			}
			free (env);
			return (ret);
		}
	}
	return (0);
}

static void	init_fileredir(t_shell *s)
{
	s->file.tmpin = 0;
	s->file.tmpout = 0;
	s->file.tmpfd = 0;
	s->file.fdin = 0;
	s->file.fdout = 0;
	s->file.ow = 0;
	s->file.ap = 0;
	s->file.input = 0;
	s->file.here_doc = 0;
	s->file.stopword = 0;
	s->file.infile = 0;
	s->file.outfile = 0;
}

static void	envinit(t_shell *shell, char **envp)
{
	int		i;

	i = ft_tablen(envp);
	shell->minienv = (char **)malloc(sizeof(char *) * (i + 1));
	if (!shell->minienv)
		malloxit();
	i = 0;
	while (envp[i])
	{
		shell->minienv[i] = ft_strdup(envp[i]);
		if (!shell->minienv[i])
			malloxit();
		i += 1;
	}
	shell->minienv[i] = 0;
	ranker(shell);
}

void	init_shell(t_shell *s, char **envp)
{
	s->minienv = 0;
	s->single_qts = 0;
	s->double_qts = 0;
	s->pipelen = 0;
	s->tilde = 0;
	s->quotes = 0;
	s->builtin = 0;
	s->cmdnotfound = 0;
	s->cmdretval = 0;
	s->error_skip = 0;
	s->syntax_error = 0;
	s->no_path = 0;
	s->file.fdin = READ;
	s->file.fdout = WRITE;
	s->pipe_two = NULL;
	envinit(s, envp);
	init_fileredir(s);
	s->path = get_paths(envp);
	if (!s->path)
		ft_exit(s, "Env path");
	s->cmd = 0;
	s->arg = 0;
}

void	reinit_shell(t_shell *s)
{
	s->no_path = 0;
	s->error_skip = 0;
	s->syntax_error = 0;
	init_fileredir(s);
	free_arr(s->path);
	s->path = get_paths(s->minienv);
	if (!s->path)
		s->no_path = 1;
	s->file.fdin = READ;
	s->file.fdout = WRITE;
	s->single_qts = 0;
	s->double_qts = 0;
	s->pipelen = 0;
	s->builtin = 0;
	s->cmd = 0;
	s->arg = 0;
}
