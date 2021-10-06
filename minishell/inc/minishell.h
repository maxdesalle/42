/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:16:49 by mdesalle          #+#    #+#             */
/*   Updated: 2021/09/30 17:58:21 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/ioctl.h>
# include <sys/stat.h>
# include <termios.h>
# include <errno.h>
# include <string.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "struct.h"
# include "../libft/libft.h"

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define READ 0
# define WRITE 1
# define MINISHELL 1
# define BASH_ERROR 2
# define PATH 5
# define START 6
# define PIPE 124
# define SINGLEQTS 39
# define DOLLARSIGN 36
# define DOUBLEQTS 34
# define BACKSLASH 92
# define MAX 1000
# define TIME 1000000

# define PROMPT "\033[0;32mminishell$\033[0m "
# define TMPFILE "tmpfile"

/*
 * PARSING
 */

int		preparse_shell(t_shell *shell, char *line);
char	**parse_arg(t_shell *s, int i);
void	init_shell(t_shell *s, char **envp);
void	reinit_shell(t_shell *s);
void	check_quotes(t_shell *s, char **arg, int i);
void	check_echo(t_shell *s, char **arg, int i);
void	check_dollar(t_shell *s, char **arg, int i);
void	check_quotes(t_shell *s, char **arg, int i);

/*
 * EXECUTION
 */

int		not_pipeable_cmd(t_shell *s);
int		not_executable_cmd(t_shell *s, char *cmd, int j);
int		heredoc_with_nocmd(t_shell *s);
void	checkfile_redir(t_shell *s);
void	cd(t_shell *shell);
void	exec_shell(t_shell *s);
void	pipe_line(t_shell *s);
void	get_fds(t_shell *s, int i);
void	get_heredoc(t_shell *s, char *word);
void	stop(t_shell *shell);
void	shell_signal(void);
void	handle_sigint(int sig);
void	handle_sigquit(int sig);
void	handle_sigusr1(int sig);
void	fork_failed(t_shell *s);
void	close_fds(t_shell *s);

/*
 * ENVIRONMENT
 */

int		change_var(t_shell *shell, char *var, char *value);
char	*get_var(t_shell *shell, char *str);
void	enver(t_shell *shell);
void	expoort(t_shell *shell, char *str);
void	unset(t_shell *shell, char *str);
char	*get_val(char *str);
int		alpharank(t_shell *shell, char *str);
void	ranker(t_shell *shell);
int		sorter(char *s1, char *s2);
void	dollar(t_shell *shell);
void	sheller(t_shell *shell);
void	exporter(t_shell *shell, int i, int j);
void	tilde(t_shell *shell, char *cmd, char *str);

/*
 * UTILS
 */

void	free_arr(char **array);
void	free_redir(t_shell *s);
int		ft_exit(t_shell *shell, char *err);
int		starts_with(char *s1, char *s2);
int		valid_dbquote(char *s, int j, int Q);
int		not_doublequote(char *s, int j);
int		get_quote_count(t_shell *sh, char *s, int i, int QUOTES);
int		is_quotes(char *s, int i, int QUOTES);
void	wait_pid(void);
void	reset_string(char **s, int i);
void	reset_shell(t_shell *s);
void	free_struct(t_shell *s);
void	ft_free(char *s);
int		bash_error_unexpected_token(t_shell *s, int err);
void	bash_error_w_filename(t_shell *s, char *file);
void	bash_error_cmd_not_found(t_shell *s, char *cmd);
void	bash_syntaxerror(t_shell *s);
void	str_replace(char **dst, char *src);
void	swap_file(t_shell *s, char **file, char **arg, int i);
void	malloxit(void);
char	**ft_presplit(t_shell *sh, char *s, char c);
char	**ft_specialsplit(t_shell *sh, char *s, char c);

#endif
