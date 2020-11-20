/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:14:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/19 16:10:20 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*newstring;

	i = 0;
	j = 0;
	len = 0;
	while (s1[i])
		i++;
	while (s2[j])
		j++;
	len = i + j;
	if (!(newstring = malloc(len + 1)))
		return (NULL);
	newstring[len] = '\0';
	while (j--)
		newstring[--len] = s2[j];
	while (i--)
		newstring[--len] = s1[i];
	return (newstring);
}
