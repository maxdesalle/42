/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:28:10 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/05 14:25:23 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

void	ft_putchar(char c, t_list *box)
{
	write(1, &c, 1);
	box->len += 1;
}

void	ft_super_putchar(int len, char c, t_list *box)
{
	while (len-- > 0)
	{
		write(1, &c, 1);
		box->len += 1;
	}
}
