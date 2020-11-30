/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:28:46 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/24 13:59:36 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*memorypointer;
	size_t	len;

	len = nmemb * size;
	if (!(memorypointer = malloc(len)))
		return (NULL);
	ft_bzero(memorypointer, len);
	return (memorypointer);
}
