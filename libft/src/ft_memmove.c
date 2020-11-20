/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:48:35 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/20 17:27:21 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*s1;
	const unsigned char	*s2;

	if (dest == src)
		return (dest);
	s1 = dest;
	s2 = src;
	if (s1 < s2)
	{
		s1 += n;
		s2 += n;
		while (n--)
			*--s1 = *--s2;
	}
	else
		while (n--)
			*s1++ = *s2++;
	return (dest);
}
