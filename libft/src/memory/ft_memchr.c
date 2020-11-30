/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:07:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/24 11:11:07 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*stringpointer;

	stringpointer = s;
	if (!n)
		return (NULL);
	while (n-- > 0)
		if (*stringpointer++ == (unsigned char)c)
			return ((void*)--stringpointer);
	return (NULL);
}
