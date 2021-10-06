/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   var.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 09:26:52 by maxdesall         #+#    #+#             */
/*   Updated: 2021/09/15 12:40:21 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

/* changes the value of the variable pointed to by *var to the value pointed */
/* to by *value */

int	change_var(t_shell *shell, char *var, char *value)
{
	int	i;

	i = 0;
	while (shell->minienv[i] && !(starts_with(var, shell->minienv[i])))
		i += 1;
	if (!shell->minienv[i])
		return (0);
	free(shell->minienv[i]);
	shell->minienv[i] = malloc(
			sizeof(char) * (ft_strlen(var) + ft_strlen(value) + 2));
	if (!shell->minienv[i])
		malloxit();
	ft_strlcpy(shell->minienv[i], var, ft_strlen(var) + 1);
	ft_strlcat(shell->minienv[i], "=", ft_strlen(shell->minienv[i]) + 2);
	ft_strlcat(shell->minienv[i], value,
		ft_strlen(shell->minienv[i]) + ft_strlen(value) + 1);
	return (1);
}

char	*get_val(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[j] && ((str[j] >= 9 && str[j] <= 13) || str[j] == ' '))
		j += 1;
	i = j;
	while (str[i] && str[i] != '=')
		i += 1;
	return (ft_substr(str, j, i));
}

/* returns a memory allocated string containing the value */
/* of the environment variable */

char	*get_var(t_shell *shell, char *str)
{
	int		i;
	int		j;
	char	*var;

	i = -1;
	while (shell->minienv[++i])
	{
		j = 0;
		while (shell->minienv[i][j] && shell->minienv[i][j] != '=')
			j += 1;
		var = ft_substr(shell->minienv[i], 0, j);
		if (!var)
			malloxit();
		if (starts_with(str, var) && (int)ft_strlen(str) == j)
		{
			free(var);
			var = ft_substr(shell->minienv[i],
					j + 1, ft_strlen(shell->minienv[i]) - j);
			if (!var)
				malloxit();
			return (var);
		}
		free(var);
	}
	return (NULL);
}
