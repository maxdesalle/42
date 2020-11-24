/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:50:52 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/24 11:08:01 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*newstring;

	len = 0;
	if (!s || !f)
		return (NULL);
	while (s[len])
		len++;
	if (!(newstring = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	newstring[len] = '\0';
	while (len-- > 0)
		newstring[len] = f(len, s[len]);
	return (newstring);
}
