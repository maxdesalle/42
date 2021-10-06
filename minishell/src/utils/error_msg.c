/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 08:59:31 by mdesalle          #+#    #+#             */
/*   Updated: 2021/10/01 11:47:28 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* 
 * unexpectedToken error displays when redirections (<,<<,>>,>)
 * are not followed by a valid file, e.g. echo hello > | cat myfile;
 * or when the pipe is misplaced
 */

int	bash_error_unexpected_token(t_shell *s, int err)
{
	if (!err)
		write(STDERR_FILENO,
			"-bash: syntax error near unexpected token `newline'\n", 52);
	else if (err == 2)
		write(STDERR_FILENO,
			"-bash: syntax error near unexpected token `|'\n", 46);
	s->syntax_error = 1;
	s->cmdretval = 2;
	return (0);
}

/* 
 * it reproduces the '-bash: cmd: command not found' message
 */

void	bash_error_cmd_not_found(t_shell *s, char *cmd)
{
	write(STDERR_FILENO, "bash: ", 6);
	write(STDERR_FILENO, cmd, ft_strlen(cmd));
	write(STDERR_FILENO, ": command not found\n", 20);
	s->cmdnotfound = 1;
	s->error_skip = 1;
	s->cmdretval = 127;
}

/* 
 * it reproduces the '-bash: Filename: error' message
 */

void	bash_error_w_filename(t_shell *s, char *file)
{
	write(STDERR_FILENO, "bash: ", 6);
	write(STDERR_FILENO, file, ft_strlen(file));
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, "No such file or directory\n", 26);
	s->error_skip = 1;
	s->cmdretval = errno;
}

/* syntax error when doublequotes or singlequotes are not closed up */

void	bash_syntaxerror(t_shell *s)
{
	write(STDERR_FILENO, "bash: quotes: parsing error\n", 28);
	s->error_skip = 1;
	s->cmdretval = 1;
}
