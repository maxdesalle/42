/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 09:21:49 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/20 11:15:35 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Credit goes to Oom (https://github.com/oomsveta) for this one. */

static size_t	word_counter(const char *s, char c)
{
	size_t len;

	len = 1;
	while (*s)
		if (*s++ == c)
			len++;
	return (len);
}

char			**ft_split(char const *s, char c)
{
	char	**splittedstring;
	size_t	len;
	int		i;
	int		j;

	len = word_counter((const char *)s, c);
	if (!(splittedstring = malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	splittedstring[len] = '\0';
	i = ft_strlen(s);
	while ((j = i--) >= 0)
	{
		while (i >= 0 && s[i] != c)
			i--;
		splittedstring[--len] = ft_substr(s, i + 1, j - i - 1);
	}
	return (splittedstring);
}
