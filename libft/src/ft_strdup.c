/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:51:26 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/24 11:07:22 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*newstring;

	len = 0;
	while (s[len])
		len++;
	if (!(newstring = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	newstring[len] = '\0';
	while (len-- > 0)
		newstring[len] = s[len];
	return (newstring);
}
