/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 07:35:18 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/26 14:24:51 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* goes to a specific directory, example: "cd some-directory" */

static void	folder(t_shell *shell, char *cmd)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!chdir(cmd))
	{
		change_var(shell, "OLDPWD", pwd);
		free(pwd);
		pwd = getcwd(NULL, 0);
		change_var(shell, "PWD", pwd);
	}
	else
	{
		perror("bash: cd");
		shell->cmdretval = errno;
	}
	free(pwd);
}

/* goes back to the home folder, example: "cd" */

static void	homer(t_shell *shell, char *str)
{
	char	*pwd;

	pwd = getcwd(NULL, 0);
	if (!pwd)
		exit(EXIT_FAILURE);
	if (!chdir(str))
	{
		if (!change_var(shell, "OLDPWD", pwd))
			exit(EXIT_FAILURE);
		pwd = getcwd(NULL, 0);
		if (!pwd)
			exit(EXIT_FAILURE);
		if (!change_var(shell, "PWD", pwd))
			exit(EXIT_FAILURE);
	}
	else
	{
		perror("cd command failed");
		shell->cmdretval = errno;
	}
	free(pwd);
}

static void	dollar_path(t_shell *shell, char *option)
{
	char	*str;
	char	*val;

	str = ft_substr(option, 1, ft_strlen(option));
	if (!str)
		exit(EXIT_FAILURE);
	val = get_var(shell, str);
	folder(shell, val);
	free(str);
	if (val)
		free(val);
}

/* redirects to the right functions */

static void	redirect(t_shell *shell, char *cmd, char *option, char *home)
{
	if (starts_with("cd", cmd) && ft_strlen(cmd) == 2)
	{
		if (!option)
			homer(shell, home);
		else
		{
			if (starts_with("~", option))
				tilde(shell, option, home);
			else if (starts_with("-", option) && ft_strlen(option) == 1)
				tilde(shell, shell->tilde, home);
			else if (starts_with("$", option))
				dollar_path(shell, option);
			else
				folder(shell, option);
		}
		shell->builtin = 1;
	}
}

/* assigns the right values to the newly created variables */
/* calls the redirection function and frees everything */

void	cd(t_shell *shell)
{
	char	*str;
	char	**tab;

	if (shell->pipelen > 1)
		return ;
	str = get_var(shell, "HOME");
	if (!str)
	{
		perror("minishell: cd: home directory not set\n");
		exit(EXIT_FAILURE);
	}
	tab = ft_split(shell->cmd[0], ' ');
	if (!tab)
		malloxit();
	redirect(shell, tab[0], tab[1], str);
	free(str);
	free_arr(tab);
}
