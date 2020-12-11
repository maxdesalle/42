/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analysis.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 08:51:16 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/11 10:07:03 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static int	ft_precision(char *str)
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
			return (precision);
		}
	}
	return (-1);
}

static int	ft_width(char *str)
{
	int	i;
	int	width;

	i = 0;
	width = 0;
	while (str[i] != '\0')
	{
		while (str[i] != '.' && (str[i] >= '0' && str[i] <= '9'))
		{
			width = ft_atoi(str);
			return (width);
		}
		i++;
	}
	return (-1);
}

static void	ft_flag(char *str, t_list *box)
{
	int	i;

	i = 0;
	box->ftag = 0;
	box->fzero = 0;
	box->fplus = 0;
	box->fminus = 0;
	box->fspace = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '#')
			box->ftag += 1;
		else if (str[i] == '0')
			box->fzero += 1;
		else if (str[i] == '+')
			box->fplus += 1;
		else if (str[i] == '-')
			box->fminus += 1;
		else if (str[i] == ' ')
			box->fspace += 1;
		i++;
	}
	return ;
}

void		ft_analysis(char *str, t_list *box)
{
	box->precision = ft_precision(str);
	box->width = ft_width(str);
	ft_flag(str, box);
}
