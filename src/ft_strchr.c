/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:23:54 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/16 14:14:58 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

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

int	main()
{
	char	c;
	char	s[] = "ceci est un tast";

	c = 'a';
	printf("%s\n%s\n", ft_strchr(s, c), strchr(s, c));
	return (0);
}
