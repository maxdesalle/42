/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expoorter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:20:20 by mdesalle          #+#    #+#             */
/*   Updated: 2021/10/01 11:42:54 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	valid_export(char *str, int i)
{
	int		start;
	char	*s;

	if (!ft_strchr(str, '='))
		return (0);
	if (!ft_isalpha(str[i]))
	{
		start = i;
		while (str[i] && (!ft_space(str[i]) && str[i] != '='))
			i++;
		s = ft_substr(str, start, i - start);
		if (!s)
			malloxit();
		printf("bash: export: \\`%s\': not a valid identifier\n", s);
		return (0);
	}
	return (1);
}

static void	assistant(t_shell *shell, char *str, char *var, int i)
{
	char	*newv;
	char	*value;

	value = ft_substr(str, i + 1, ft_strlen(str));
	if (!value)
		malloxit();
	newv = get_var(shell, var);
	if (newv == NULL)
		expoort(shell, str);
	else
	{
		if (!change_var(shell, var, value))
			exit(EXIT_FAILURE);
	}
	free(newv);
	free(value);
}

/* prepares the variables for the expoort function or the change_var */
/* function if the variable already exists */

void	exporter(t_shell *shell, int i, int j)
{
	char	*var;
	char	**tab;

	tab = ft_split_quotes(shell->cmd[0]);
	while (!ft_strcmp(tab[j], "export"))
		j += 1;
	while (tab[j])
	{
		i = 0;
		if (valid_export(tab[j], i))
		{
			while (tab[j][i] && tab[j][i] != '=')
				i += 1;
			var = ft_substr(tab[j], 0, i);
			if (!var)
				malloxit();
			assistant(shell, tab[j], var, i);
			free(var);
		}
		else if (ft_strcmp("export", tab[j]))
			printf("bash: export: `%s': not a valid identifier\n", tab[j]);
		j += 1;
	}
	free_arr(tab);
}
