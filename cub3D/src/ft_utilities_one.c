/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:00:27 by mdesalle          #+#    #+#             */
/*   Updated: 2021/02/18 11:26:07 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int     ft_atoi_char(char c)
{
	if (c == 'N')
		return (3);
	if (c == 'S')
		return (4);
	if (c == 'E')
		return (5);
	if (c == 'W')
		return (6);
	return (c - '0');
}

size_t	ft_strlen_alpha(const char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (s[i] != '\0')
	{
		if (s[i] != ' ')
			len++;
		i++;
	}
	return (len);
}

char    *ft_strchr(const char *s, int c)
{
	if (c == '\0')
	{
		while (*s)
			s++;
		return ((char*)s);
	}
	while (*s)
		if (*s++ == c)
			return ((char*)--s);
	return (NULL);
}
