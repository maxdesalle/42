/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:51:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/03 10:44:59 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

int	ft_precision(char *str)
{
	int	i;
	int	precision;

	i = 0;
	precision = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '.')
			i++;
		if (str[i] == '.')
		{
			i++;
			while (str[i] >= '0' && str[i] <= '9')
				precision = precision * 10 + (str[i++] - '0');
			return (precision)
		}
	}
	return (-1);
}

int	ft_width(char *str)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (str[i] != '\0')
	{
		while (!(str[i] >= '0' && str[i] <= '9'))
			i++;
		while (str[i] != '.')
		{
			while (str[i] >= '0' && str[i] <= '9')
				width = width * 10 + (str[i++] - '0');
			return (width);
		}
	}
	return (-1);
}

void	ft_analysis(char *str, va_list argptr)
{
	node_t	box;

	box.precision = ft_precision(str);
	box.width = ft_width(str);
