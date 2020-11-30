/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 13:31:20 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/24 13:25:40 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*stringpointer;

	stringpointer = s;
	while (n-- > 0)
		*stringpointer++ = (unsigned char)c;
	return (s);
}
