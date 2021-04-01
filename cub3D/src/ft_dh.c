/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dh.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:05:52 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/01 17:31:16 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_height(v_list *c)
{
	if (c->ray.sde == 0)
		c->ray.prp = ((double)c->ray.mx - c->ray.px
				+ (1 - (double)c->ray.sx) / 2) / c->ray.rdx;
	else if (c->ray.sde == 1)
		c->ray.prp = ((double)c->ray.my - c->ray.py
				+ (1 - (double)c->ray.sy) / 2) / c->ray.rdy;
	c->ray.lh = (int)(c->res.ry / c->ray.prp);
	c->ray.ds = -c->ray.lh / 2 + c->res.ry / 2;
	if (c->ray.ds < 0)
		c->ray.ds = 0;
	c->ray.de = c->ray.lh / 2 + c->res.ry / 2;
	if (c->ray.de >= c->res.ry || c->ray.de < 0)
		c->ray.de = c->res.ry - 1;
}

void	ft_delta(v_list *c)
{
	if (c->ray.rdy == 0)
	{
		c->ray.ddx = 0;
		c->ray.ddy = 1;
	}
	if (c->ray.rdx == 0)
	{
		c->ray.ddx = 1;
		c->ray.ddy = 0;
	}
	else
	{
		c->ray.ddx = sqrt(1 + (c->ray.rdy
					* c->ray.rdy) / (c->ray.rdx
					* c->ray.rdx));
		c->ray.ddy = sqrt(1 + (c->ray.rdx
					* c->ray.rdx) / (c->ray.rdy
					* c->ray.rdy));
	}
}
