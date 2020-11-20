/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 09:13:29 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/18 10:08:42 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*s1;
	char const	*s2;

	s1 = dest;
	s2 = src;
	while (n--)
	{
		*s1++ = *s2;
		if (*s2 == c)
			return ((void*)s1);
		s2++;
	}
	return (NULL);
}
