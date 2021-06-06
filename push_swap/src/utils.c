/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 11:01:19 by mdesalle          #+#    #+#             */
/*   Updated: 2021/06/06 11:15:31 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../include/push_swap.h"

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
	return (sign * result);
}
