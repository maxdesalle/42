/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 07:53:52 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/20 08:50:32 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	is_in_set(char c, const char *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

char				*ft_strtrim(char const *s1, char const *set)
{
	int		len;
	char	*start;
	char	*end;

	len = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[len])
		len++;
	start = (char *)s1;
	end = (char *)s1 + len - 1;
	while (is_in_set(*start, set))
		start++;
	while (is_in_set(*end, set))
		end--;
	return (ft_substr(s1, start - s1, end - start + 1));
}
