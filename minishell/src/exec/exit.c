/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 10:56:49 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/30 17:20:48 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static void	tabtwo(t_shell *shell, char **cmd)
{
	if (ft_strlen(cmd[1]) < 20 && ft_isnumber(cmd[1]))
	{
		printf("exit\n");
		free_arr(shell->cmd);
		exit(ft_atoi(cmd[1]));
	}
	else
	{
		printf("exit\n");
		printf("bash: exit: %s: numeric argument required\n", cmd[1]);
		free_arr(shell->cmd);
		exit(BASH_ERROR);
	}
}

/* checks if the command "exit" was put in the s, and exits if that's */
/* the case */

void	stop(t_shell *s)
{
	char	**cmd;

	if (!starts_with("exit", s->cmd[0]))
		return ;
	if (!ft_strcmp("exit", s->cmd[0]))
	{
		write(2, "exit\n", 5);
		free_arr(s->cmd);
		exit(EXIT_SUCCESS);
	}
	cmd = ft_split(s->cmd[0], ' ');
	if (!cmd)
		malloxit();
	if (ft_tablen(cmd) == 2)
		tabtwo(s, cmd);
	else if (ft_tablen(cmd) > 2)
	{
		write(2, "exit\n", 5);
		write(2, "bash: exit: too many arguments\n", 31);
		free_arr(s->cmd);
		free_arr(cmd);
		s->builtin = 1;
		exit(EXIT_FAILURE);
	}	
}
