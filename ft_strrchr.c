/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 17:57:04 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/16 19:07:24 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*stringpointer;
	
	stringpointer = (char *)s;
	while (*stringpointer)
		stringpointer++;
	while (stringpointer--)
		if (*stringpointer == c)
			return (stringpointer);
	return (NULL);
}
