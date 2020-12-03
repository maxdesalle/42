/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:24:47 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/03 15:40:20 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_type_check(char c)
{
	return (c == 'c' ||
		c == 's' ||
		c == 'p' ||
		c == 'd' ||
		c == 'i' ||
		c == 'u' ||
		c == 'x' ||
		c == 'X' ||
		c == '%');
}

int			ft_parser(va_list argptr, const char *str)
{
	int	i;
	int	len;

	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] == '%')
		{
			ft_putchar('%');
			i++;
			len++;
		}
		else if (str[i] == '%' && str[i + 1] != '%')
		{
			while (ft_type_check(str[i]) == 0)
				i++;
		}
		if (str[i] != '%' && str[i + 1] != '%')
		{
			ft_putchar(str[i]);
			len++;
		}
		i++;
	}
	return (len);
}
