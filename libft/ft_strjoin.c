/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 10:14:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/19 11:07:03 by mdesalle         ###   ########.fr       */
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
	while (s1[len])
		len++;
	while (s2[len])
		len++;
	if (!(newstring = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	while (s1[i])
		(newstring[i] = s1[i]) && i++;
	while (s2[j])
		(newstring[i + j] = s2[j]) && j++;
	newstring[i + j] = '\0';
	return (newstring);
}
