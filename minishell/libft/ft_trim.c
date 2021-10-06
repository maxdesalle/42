/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlazzare <mlazzare@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 11:59:24 by mlazzare          #+#    #+#             */
/*   Updated: 2021/09/15 13:27:17 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_trim(char *s)
{
	int		i;
	int		k;
	int		len;
	char	*r;

	if (!s)
		return (NULL);
	i = 0;
	k = 0;
	len = (int)ft_strlen(s) - 1;
	while (s[i] && ft_space(s[i]))
		i++;
	while (len > i && s[len] && ft_space(s[len]))
		len--;
	r = (char *)malloc(sizeof(char) * (len - i + 2));
	if (!r)
		return (NULL);
	while (i <= len)
		r[k++] = s[i++];
	r[k] = '\0';
	return (r);
}
