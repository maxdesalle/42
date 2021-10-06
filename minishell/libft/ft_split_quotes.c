/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_quotes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 08:54:37 by mlazzare          #+#    #+#             */
/*   Updated: 2021/10/01 11:44:25 by mlazzare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define MAX 1000

static int	word_count(const char *s)
{
	int	i;
	int	QUOTE;
	int	count;

	if (!s || !s[0])
		return (0);
	i = -1;
	count = 0;
	while (s[++i])
	{
		if (s[i] == '"' || s[i] == '\'')
		{
			QUOTE = s[i];
			i += 1;
			while (s[i] && s[i] != QUOTE)
				i += 1;
		}
		if (s[i] && ((!ft_space(s[i]) && ft_space(s[i + 1]))
				|| (!ft_space(s[i]) && s[i + 1] == '\0')))
			count++;
	}
	return (count);
}

static char	**freetab(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
	return (0);
}

static char	*get_line(const char *s, int *i)
{
	int		QUOTE;
	int		j;
	char	*line;

	j = 0;
	line = (char *)malloc(sizeof(char) * (MAX + 1));
	if (!line)
		return (NULL);
	while (s[(*i)] && ft_space(s[(*i)]))
		(*i) += 1;
	while (s[(*i)] && !ft_space(s[(*i)]))
	{
		if (s[(*i)] == '"' || s[(*i)] == '\'')
		{
			QUOTE = s[(*i)];
			(*i) += 1;
			while (s[(*i)] && s[(*i)] != QUOTE)
				line[j++] = s[(*i)++];
			(*i) += 1;
		}
		else if (!ft_space(s[(*i)]))
			line[j++] = s[(*i)++];
	}
	line[j] = '\0';
	return (line);
}

static char	**fill_arr(int words, const char *s, char **arr)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	arr[0] = 0;
	while (++k < words)
	{
		arr[k] = get_line(s, &i);
		if (!arr[k])
			return (freetab(arr));
	}
	arr[k] = 0;
	return (arr);
}

char	**ft_split_quotes(char const *s)
{
	int		words;
	char	**arr;

	if (!s)
		return (NULL);
	words = word_count(s);
	arr = (char **)malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	arr = fill_arr(words, s, arr);
	return (arr);
}
