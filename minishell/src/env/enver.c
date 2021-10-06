/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enver.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 10:13:13 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/21 08:51:15 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* prepares the variables for the unset function */

static void	unsetter(t_shell *shell)
{
	int		i;
	char	**str;

	i = 0;
	str = ft_split(shell->cmd[0], ' ');
	while (str[++i])
		unset(shell, str[i]);
	free_arr(str);
}

/* reproduces the behaviour of the "export" command */

static void	exprint(t_shell *shell)
{
	int	i;
	int	j;

	i = 0;
	while (shell->minienv[i])
	{
		j = 0;
		printf("declare -x ");
		while (shell->minienv[i][j] != '=')
		{
			printf("%c", shell->minienv[i][j]);
			j += 1;
		}
		printf("%s", "=\"");
		j += 1;
		while (shell->minienv[i][j])
		{
			printf("%c", shell->minienv[i][j]);
			j += 1;
		}
		printf("%c\n", '"');
		i += 1;
	}
}

void	enver(t_shell *shell)
{
	int	i;

	i = 0;
	if (starts_with("env", shell->cmd[0]))
	{
		while (shell->minienv[i])
		{
			printf("%s\n", shell->minienv[i]);
			i += 1;
		}
	}
	else if (starts_with("unset ", shell->cmd[0]))
		unsetter(shell);
	else if (!ft_strcmp("export", shell->cmd[0]))
		exprint(shell);
	else if (starts_with("export ", shell->cmd[0]))
		exporter(shell, 0, 1);
	else
		return ;
	shell->builtin = 1;
}
