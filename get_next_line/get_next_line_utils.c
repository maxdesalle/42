/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:07:40 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/26 16:13:01 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*substring;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	while (s[j])
		j++;
	if (!(substring = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start < j)
	{
		while (s[start] && len--)
		{
			substring[i] = s[start];
			start++;
			i++;
		}
	}
	substring[i] = '\0';
	return (substring);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*newstring;

	i = 0;
	j = 0;
	len = 0;
	if (!s1 || !s2)
		return (NULL);
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	len = i + j;
	if (!(newstring = malloc(len + 1)))
		return (NULL);
	newstring[len] = '\0';
	while (j-- > 0)
		newstring[--len] = s2[j];
	while (i-- > 0)
		newstring[--len] = s1[i];
	return (newstring);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
