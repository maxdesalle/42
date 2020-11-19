/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 09:28:46 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/19 09:45:33 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char			*memorypointer;
	unsigned int	value;
	unsigned int	i;

	i = 0;
	value = nmemb * size;
	if (!(memorypointer = malloc(value)))
		return (NULL);
	while (value--)
		memorypointer[i++] = 0;
	return ((void *)memorypointer);
}
