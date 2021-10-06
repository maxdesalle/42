/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dsh.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 11:41:46 by mdesalle          #+#    #+#             */
/*   Updated: 2021/09/22 14:41:54 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* executes environment variable commands */

void	dollar(t_shell *shell)
{
	char	*tmp;

	tmp = ft_substr(shell->cmd[0], 1, ft_strlen(shell->cmd[0]));
	if (!tmp)
		malloxit();
	free(shell->cmd[0]);
	shell->cmd[0] = get_var(shell,
			ft_substr(shell->cmd[0], 1, ft_strlen(shell->cmd[0])));
	if (!shell->cmd[0])
		exit(EXIT_FAILURE);
	free(tmp);
}

/* increments by one the SHLVL environment variable */

void	sheller(t_shell *shell)
{
	int		lvl;
	char	*tmp;

	tmp = get_var(shell, "SHLVL");
	if (!tmp)
		malloxit();
	lvl = ft_atoi(tmp);
	free(tmp);
	lvl += 1;
	tmp = ft_itoa(lvl);
	change_var(shell, "SHLVL", tmp);
	free(tmp);
}
