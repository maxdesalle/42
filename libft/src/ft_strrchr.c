/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:57:04 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/21 12:13:34 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*stringpointer;

	stringpointer = (char*)s;
	while (*stringpointer)
		stringpointer++;
	if (c == '\0')
		return ((char*)stringpointer);
	while (stringpointer-- >= s)
		if (*stringpointer == c)
			return ((char*)stringpointer);
	return (NULL);
}
