/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:07:40 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/29 08:43:49 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3D.h"

/*
** creates a new string using a part of the content of another string.
*/

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

/*
** joins two strings in a new memory-allocated string.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*newstring;

	if (!s1 && !s2)
	{
		free((char *)s1);
		return (0);
	}
	i = ft_strlen((char *)s1);
	j = ft_strlen((char *)s2);
	len = i + j;
	if (!(newstring = malloc(sizeof(char) * (len + 1))))
	{
		free((char *)s1);
		return (0);
	}
	newstring[len] = '\0';
	while (j-- > 0)
		newstring[--len] = s2[j];
	while (i-- > 0)
		newstring[--len] = s1[i];
	free((char *)s1);
	return (newstring);
}

/*
** a modified version of the strcat function which starts copying the
** content of a string at a certain point in the string in a completely
** new string. the source string is freed and the destination string is
** ended with \0 and returned.
*/

char	*ft_strcat_alpha(char *dest, char *src, int len)
{
	int	i;

	i = 0;
	while (src[len] != '\0')
		dest[i++] = src[len++];
	dest[i] = '\0';
	free(src);
	return (dest);
}
