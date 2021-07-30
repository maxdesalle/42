/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:07:50 by maxdesall         #+#    #+#             */
/*   Updated: 2021/07/30 09:59:32 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

static char	*nullturn(char const *s1)
{
	free((char *)s1);
	return (NULL);
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
	if (!s1 && !s2)
		return (nullturn(s1));
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	len = i + j;
	newstring = malloc(sizeof(char) * (len + 1));
	if (!newstring)
		return (nullturn(s1));
	newstring[len] = '\0';
	while (j-- > 0)
		newstring[--len] = s2[j];
	while (i-- > 0)
		newstring[--len] = s1[i];
	free((char *)s1);
	return (newstring);
}
