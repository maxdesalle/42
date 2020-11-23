/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:21:49 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/23 10:33:43 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		string_number(char const *s1, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!(*s1))
		return (0);
	while (*s1)
	{
		if (*s1 == c)
			j = 0;
		else if (j == 0)
		{
			j = 1;
			i++;
		}
		s1++;
	}
	return (i);
}

static int		modified_strlen(char const *s2, char c, int i)
{
	int	len;

	len = 0;
	while (s2[i] && s2[i] != c)
	{
		len++;
		i++;
	}
	return (len);
}

static char		**clear_split(char const **dest, int j)
{
	while (j--)
		free((void *)dest[j]);
	free(dest);
	return (NULL);
}

static char		**create_split(char const *s, char **dest, char c, int l)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < l)
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (!(dest[j] = malloc(sizeof(char) * (modified_strlen(s, c, i) + 1))))
			return (clear_split((char const **)dest, j));
		while (s[i] && s[i] != c)
			dest[j][k++] = s[i++];
		dest[j][k] = '\0';
		j++;
	}
	dest[j] = 0;
	return (dest);
}

char			**ft_split(char const *s, char c)
{
	char	**dest;
	int		l;

	if (s == NULL)
		return (NULL);
	l = string_number(s, c);
	if (!(dest = (char **)malloc(sizeof(char *) * (l + 1))))
		return (NULL);
	return (create_split(s, dest, c, l));
}
