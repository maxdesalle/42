/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:23:54 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/16 16:57:53 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*stringpointer;

	stringpointer = (char *)s;
	while (*stringpointer != c)
	{
		if (*stringpointer == '\0')
			return (NULL);
		stringpointer++;
	}
	return (stringpointer);
}
