/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maxdesalle <mdesalle@student.s19.be>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:00:15 by maxdesall         #+#    #+#             */
/*   Updated: 2021/08/09 12:03:48 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/philo.h"

static int	ft_return(int result, int sign)
{
	result *= sign;
	if (result > 0 && sign < 0)
		return (errtoi());
	if (result < 0 && sign > 0)
		return (errtoi());
	return (result);
}

int	is_empty(char c)
{
	return ((c >= 9 && c <= 13) || c == ' ');
}

int	is_sign(char c)
{
	return (c == '+' || c == '-');
}

int	is_num(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] && is_empty(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	i += is_sign(str[i]);
	while (str[i] && is_num(str[i]))
		result = result * 10 + (str[i++] - '0');
	return (ft_return(result, sign));
}
