/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 11:34:55 by mdesalle          #+#    #+#             */
/*   Updated: 2020/11/20 18:04:26 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int				sign;
	long long int	result;

	result = 0;
	sign = 1;
	while (*nptr <= 32)
		nptr++;
	if (*nptr == '+' || *nptr == '-')
		*nptr++ == '-' && (sign = -1);
	while (*nptr >= '0' && *nptr <= '9')
		if ((result = result * 10 + *nptr++ - '0') < 0)
			(~sign ? -1 : 0);
	return (sign * result);
}
