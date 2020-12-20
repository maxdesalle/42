/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 11:24:47 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/20 16:07:30 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_craft1(va_list argptr, t_list *box)
{
	if (box->type == 'c')
		ft_c_craft(va_arg(argptr, int), box);
	else if (box->type == 's')
		ft_s_craft(va_arg(argptr, char *), box);
	else
		ft_di_craft(va_arg(argptr, int), box);
}

static void	ft_craft2(va_list argptr, t_list *box)
{
	if (box->type == 'u')
		ft_u_craft(va_arg(argptr, unsigned int), box);
	else if (box->type == 'x')
		ft_xx_craft(va_arg(argptr, unsigned int), 0, box);
	else if (box->type == 'X')
		ft_xx_craft(va_arg(argptr, unsigned int), 1, box);
}

static void	ft_type_selector(va_list argptr, t_list *box)
{
	if (box->type == 'c' || box->type == 's' || box->type == 'd'
			|| box->type == 'i')
		ft_craft1(argptr, box);
	else
		ft_craft2(argptr, box);
}

int			ft_parser(va_list argptr, char *str, t_list *box)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			ft_analysis(&str[++i], box);
			while (ft_strchr("cspdiuxX", str[i]) == NULL)
				i++;
			if (ft_strchr("cspdiuxX", str[i]))
				box->type = str[i];
			ft_type_selector(argptr, box);
		}
		else if (str[i] == '%' && str[i + 1] == '%')
			ft_putchar(str[++i], box);
		else
			ft_putchar(str[i], box);
		i++;
	}
	return (box->len);
}
