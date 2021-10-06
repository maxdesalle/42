/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_presplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneve <gneve@student.s19.be>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 08:59:17 by mdesalle          #+#    #+#             */
/*   Updated: 2021/09/26 14:36:56 by gneve            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

static int	skip_ahead2pipe(t_shell *sh, char *s, int i, int QUOTES)
{
	int	q;

	q = 1;
	i += 1;
	while (s[i])
	{
		if (is_quotes(s, i, QUOTES))
			q++;
		if ((s[i + 1] == PIPE && !(q & 1)) || !s[i + 1])
			break ;
		i++;
	}
	if (q & 1)
		bash_syntaxerror(sh);
	return (i);
}

static char	*cpystr_up2pipe(t_shell *sh, char *s, int *i)
{
	int		end;
	int		start;

	start = *i;
	while (s[*i])
	{
		if (s[*i] == SINGLEQTS)
			*i = skip_ahead2pipe(sh, s, *i, SINGLEQTS);
		else if (s[*i] == DOUBLEQTS)
			*i = skip_ahead2pipe(sh, s, *i, DOUBLEQTS);
		if (s[*i] == PIPE || !s[*i + 1])
		{
			if (s[*i] == PIPE && !s[*i + 1])
				bash_error_unexpected_token(sh, 2);
			end = *i;
			if (!s[*i + 1])
				end += 1;
			return (ft_substr(s, start, end - start));
		}
		(*i)++;
	}		
	return (NULL);
}

static int	word_count(t_shell *sh, char *s, char c)
{
	int	i;
	int	count;

	if (!s || !s[0])
		return (0);
	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == SINGLEQTS)
			i = skip_ahead2pipe(sh, s, i, SINGLEQTS);
		else if (s[i] == DOUBLEQTS)
			i = skip_ahead2pipe(sh, s, i, DOUBLEQTS);
		if ((s[i] != c && s[i + 1] == c) || (s[i] != c
				&& s[i + 1] == '\0'))
			count++;
	}
	return (count);
}

static char	**fill_arr(t_shell *sh, int words, char *s, char c)
{
	int		i;
	int		k;
	char	**arr;

	i = 0;
	k = 0;
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	while (!sh->error_skip && k < words)
	{
		while (s[i] && s[i] == c)
			i++;
		arr[k] = cpystr_up2pipe(sh, s, &i);
		if (!arr[k])
		{
			free_arr(arr);
			return (NULL);
		}
		k++;
	}
	arr[k] = 0;
	return (arr);
}

char	**ft_presplit(t_shell *sh, char *s, char c)
{
	int		words;

	if (!s)
		return (NULL);
	words = word_count(sh, s, c);
	return (fill_arr(sh, words, s, c));
}
