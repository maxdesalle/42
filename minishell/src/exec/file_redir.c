/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 15:17:14 by mlazzare          #+#    #+#             */
/*   Updated: 2021/09/30 12:23:56 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	redir_output(t_shell *s)
{
	if (s->file.ow)
		s->file.fdout = open(s->file.outfile,
				O_CREAT | O_RDWR | O_TRUNC, 0644);
	else if (s->file.ap)
		s->file.fdout = open(s->file.outfile,
				O_CREAT | O_RDWR | O_APPEND, 0644);
	if (s->file.fdout < 0)
		bash_error_w_filename(s, s->file.outfile);
	ft_free(s->file.outfile);
}

static void	redir_input(t_shell *s)
{
	if (s->file.infile)
		s->file.fdin = open(s->file.infile, O_RDONLY);
	if (s->file.fdin < 0)
		bash_error_w_filename(s, s->file.infile);
	ft_free(s->file.infile);
}

void	checkfile_redir(t_shell *s)
{
	if (s->file.stopword)
		get_heredoc(s, 0);
	else if (s->file.infile)
		redir_input(s);
	if (s->file.outfile)
		redir_output(s);
}
