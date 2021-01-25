/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 20:55:38 by mdesalle          #+#    #+#             */
/*   Updated: 2021/01/25 11:55:38 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_pow(double x, double y)
{
	double	result;

	result = x;
	if (y-- == 0)
		return (0);
	while (y-- > 0)
		result *= x;
	return (result);
}
