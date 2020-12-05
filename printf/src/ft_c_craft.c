/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_c_craft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/05 13:20:17 by mdesalle          #+#    #+#             */
/*   Updated: 2020/12/05 14:22:08 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/printf.h"

static void	ft_first_case(t_list *box)
{
	if (box->width > 1 && box->fminus == 1)
	{
		ft_putchar(box->c, box);
		ft_super_putchar(box->width - 1, ' ', box);
		return ;
	}
	else if (box->width > 1 && box->fzero == 1)
		ft_super_putchar(box->width - 1, '0', box);
	else if (box->width > 1 && box->fminus == 0)
		ft_super_putchar(box->width - 1, ' ', box);
	ft_putchar(box->c, box);
	return ;
}

void	ft_c_craft(t_list *box)
{
	if (box->width > 1)
		ft_first_case(box);
	else
		ft_putchar(box->c, box);
}
