/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:14:17 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/02 16:11:57 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/pipex.h"

char	*ft_strdup(const char *s)
{
	int		len;
	char	*newstring;

	len = 0;
	while (s[len])
		len++;
	newstring = malloc(sizeof(char) * (len + 1));
	if (!newstring)
		return (NULL);
	newstring[len] = '\0';
	while (len-- > 0)
		newstring[len] = s[len];
	return (newstring);
}
