/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specialsplit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/15 12:15:12 by mdesalle          #+#    #+#             */
/*   Updated: 2021/09/30 12:00:25 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/minishell.h"

int	cpystr_w_quotes(char *s, char *arr, int i, int Q)
{
	int	j;

	j = 0;
	arr[j++] = s[i];
	while (s[++i] && !(s[i] == Q && s[i - 1] != BACKSLASH))
		if (Q == SINGLEQTS || valid_dbquote(s, i, Q))
			arr[j++] = s[i];
	arr[j] = s[i];
	arr[j + 1] = '\0';
	return (i + 1);
}

int	cpystr_w_char(char *s, char *arr, int i)
{
	int	j;

	j = 0;
	while (s[i] && !ft_space(s[i]))
		arr[j++] = s[i++];
	arr[j] = '\0';
	return (i);
}

static int	word_count(t_shell *sh, char *s)
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
		{
			i = get_quote_count(sh, s, i, SINGLEQTS);
			count++;
		}
		else if (s[i] == DOUBLEQTS)
		{
			i = get_quote_count(sh, s, i, DOUBLEQTS);
			count++;
		}
		else if ((!ft_space(s[i]) && ft_space(s[i + 1]))
			|| (!ft_space(s[i]) && s[i + 1] == '\0'))
			count++;
	}
	return (count);
}

static char	**fill_arr(int words, char *s, char **arr)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < words)
	{
		arr[k] = (char *)malloc(sizeof(char) * (MAX + 1));
		if (!arr[k])
		{
			free_arr(arr);
			return (NULL);
		}
		while (s[i] && ft_space(s[i]))
			i++;
		if ((s[i] && s[i] == SINGLEQTS))
			i = cpystr_w_quotes(s, arr[k], i, SINGLEQTS);
		else if ((s[i] && s[i] == DOUBLEQTS))
			i = cpystr_w_quotes(s, arr[k], i, DOUBLEQTS);
		else
			i = cpystr_w_char(s, arr[k], i);
		k++;
	}
	arr[k] = 0;
	return (arr);
}

char	**ft_specialsplit(t_shell *sh, char *s, char c)
{
	char	**arr;
	int		words;

	if (!s)
		return (NULL);
	(void)c;
	words = word_count(sh, s);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	return (fill_arr(words, s, arr));
}
