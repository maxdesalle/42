/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 09:17:14 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/16 16:51:28 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*s;
	long	x;
	int	len;
	int	tmp;

	x = n;
	tmp = x;
	len = 0;
	while (tmp)
	{
		tmp /= 10;
		len++;
	}
	if (x < 0)
		len++;
	if (!(s = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	s[len--] = '\0';
	if (x == 0)
		s[0] = '0';
	if (x < 0)
	{
		s[0] = '-';
		x *= -1;
	}
	while (x > 0)
	{
		s[len--] = x % 10 + '0';
		x /= 10;
	}
	return (s);
}
