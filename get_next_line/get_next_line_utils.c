/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:07:40 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/28 10:52:07 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == 0)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

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

char		*ft_strjoin(char const *s1, char const *s2)
{
	int	i;
	int	j;
	int	len;
	char	*newstring;

	if (!s1 && !s2)
		return (0);
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	len = i + j;
	if (!(newstring = malloc(len + 1)))
		return (0);
	newstring[len] = '\0';
	while (j-- > 0)
		newstring[--len] = s2[j];
	while (i-- > 0)
		newstring[--len] = s1[i];
	return (newstring);
}
