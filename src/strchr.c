/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strchr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 10:23:54 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/16 11:00:13 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*sp;

	while (*s)
	{
		if (*s++ == c)
			*sp = s;
		else
			return (NULL);
	}
	return (sp);
}

int	main()
{
	char	c;
	char	s[] = "ceci est un tast";

	c = 'a';
	printf("%s\n%s\n", ft_strchr(s, c), strchr(s, c));
	return (0);
}
