/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 16:08:28 by mlazzare          #+#    #+#             */
/*   Updated: 2021/09/30 12:28:53 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	write2tmpfile(t_shell *s, char *word)
{
	write(s->file.tmpfd, word, ft_strlen(word));
	write(s->file.tmpfd, "\n", 1);
	ft_free(word);
}

static int	ctrld_eof_error(t_shell *shell)
{
	char	*str;

	str = ft_substr(shell->cmd[0], 3, ft_strlen(shell->cmd[0]));
	ft_putstr_fd("bash: warning: ", STDERR);
	ft_putstr_fd("here-document at line 1 delimited by end-of-file ", STDERR);
	ft_putstr_fd("(wanted `", STDERR);
	ft_putstr_fd(str, STDERR);
	ft_putstr_fd("')\n", STDERR);
	free(str);
	return (1);
}

static void	redir_heredoc(t_shell *s)
{
	close(s->file.tmpfd);
	if (s->file.here_doc)
		s->file.fdin = open(TMPFILE, O_RDWR);
	if (s->file.fdin < 0)
		bash_error_w_filename(s, s->file.infile);
	unlink(TMPFILE);
}

int	heredoc_with_nocmd(t_shell *s)
{
	char	*word;

	if (!s->file.stopword || (s->file.stopword && s->arg[0]))
		return (0);
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		word = readline("> ");
		if (!word)
			return (ctrld_eof_error(s));
		if (!ft_strcmp(word, s->file.stopword))
			break ;
		free(word);
	}
	free(word);
	free(s->file.stopword);
	s->file.stopword = 0;
	checkfile_redir(s);
	return (1);
}

void	get_heredoc(t_shell *s, char *word)
{
	s->file.tmpfd = open(TMPFILE, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (s->file.tmpfd < 0)
		ft_exit(s, "Tmpfile");
	while (1)
	{
		signal(SIGQUIT, SIG_IGN);
		word = readline("> ");
		if (!word)
		{
			ctrld_eof_error(s);
			break ;
		}
		if (!ft_strcmp(word, s->file.stopword))
			break ;
		write2tmpfile(s, word);
	}
	ft_free(word);
	if (not_executable_cmd(s, s->arg[0], -1))
	{
		ft_free(s->file.stopword);
		s->error_skip = 1;
		return ;
	}
	redir_heredoc(s);
	ft_free(s->file.stopword);
}
