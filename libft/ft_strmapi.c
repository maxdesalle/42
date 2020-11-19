/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 16:50:52 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/19 16:58:19 by mdesalle         ###   ########.fr       */
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
	while (len--)
		newstring[len] = f(len, s[len]);
	return (newstring);
}
