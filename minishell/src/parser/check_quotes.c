/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 10:45:52 by mlazzare          #+#    #+#             */
/*   Updated: 2021/09/24 07:06:57 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	is_dollar(char *s, int i)
{
	return ((i == 0 && s[i] == DOLLARSIGN)
		|| (i > 0 && s[i] == DOLLARSIGN && s[i - 1] != BACKSLASH));
}

static char	*overwrite_dollarvalue(t_shell *s, char *str, int *j)
{
	int		start;
	char	*value;
	char	*var;

	start = *j;
	while (str[*j] && ft_isalnum(str[*j]))
		(*j)++;
	value = ft_substr(str, start, *j - start);
	(*j)--;
	if (!value)
		malloxit();
	var = get_var(s, value);
	ft_free(value);
	if (!var)
		return (ft_strdup(""));
	return (var);
}

static void	doubleqts_stringify(t_shell *s, char **arg, int i)
{
	int		j;
	int		k;
	char	*tmp;
	char	*var;

	k = 0;
	j = 0;
	tmp = malloc(sizeof(char) * (MAX + 1));
	if (!tmp)
		malloxit();
	memset(tmp, 0, MAX + 1);
	while (arg[i][++j] && arg[i][j + 1])
	{
		if (is_dollar(arg[i], j))
		{
			j++;
			var = overwrite_dollarvalue(s, arg[i], &j);
			k = ft_strlcat(tmp, var, MAX + 1);
			ft_free(var);
		}
		else
			tmp[k++] = arg[i][j];
	}
	tmp[k] = 0;
	str_replace(&arg[i], tmp);
}

/*
*This function removes single quotes from the string
*/

static void	singleqts_stringify(char **arg, int i)
{
	int		j;
	int		k;
	char	*tmp;

	j = -1;
	k = 0;
	tmp = malloc(sizeof(char) * (MAX + 1));
	if (!tmp)
		malloxit();
	while (arg[i][++j])
		if (arg[i][j] != SINGLEQTS)
			tmp[k++] = arg[i][j];
	tmp[k] = 0;
	str_replace(&arg[i], tmp);
}

void	check_quotes(t_shell *s, char **arg, int i)
{
	if (starts_with("\'", arg[i]))
		s->single_qts = 1;
	else if (starts_with("\"", arg[i]))
		s->double_qts = 1;
	if (s->single_qts)
		singleqts_stringify(arg, i);
	else if (s->double_qts)
		doubleqts_stringify(s, arg, i);
	s->double_qts = 0;
}
