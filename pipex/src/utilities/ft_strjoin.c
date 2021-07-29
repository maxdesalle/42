/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 17:07:50 by maxdesall         #+#    #+#             */
/*   Updated: 2021/07/29 17:08:01 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

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
	if (!(newstring = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	newstring[len] = '\0';
	while (j-- > 0)
		newstring[--len] = s2[j];
	while (i-- > 0)
		newstring[--len] = s1[i];
	return (newstring);
}
