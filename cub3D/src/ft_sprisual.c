/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprisual.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:45:48 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/01 18:36:53 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_sprcalc(v_list *c)
{
	c->spr.dsy = -c->spr.sph / 2 + c->res.ry / 2;
	c->spr.dey = c->spr.sph / 2 + c->res.ry / 2;
	if (c->spr.dsy < 0)
		c->spr.dsy = 0;
	if (c->spr.dey >= c->res.ry)
		c->spr.dey = c->res.ry;
	c->spr.spw = abs((int)(c->res.ry / c->spr.tfy));
	c->spr.dsx = -c->spr.spw / 2 + c->spr.ssx;
	c->spr.dex = c->spr.spw / 2 + c->spr.ssx;
	if (c->spr.dsx < 0)
		c->spr.dsx = 0;
	if (c->spr.dex >= c->res.rx)
		c->spr.dex = c->res.rx;
}

void	ft_order(v_list *c)
{
	int	i;

	i = -1;
	while (++i < c->spr.spc)
	{
		c->spr.spo[i] = i;
		c->spr.spd[i] = ((c->ray.px - c->spr.sx[i]) * (c->ray.px
					- c->spr.sx[i]) + (c->ray.py
					- c->spr.sy[i])
				* (c->ray.py - c->spr.sy[i]));
	}
}

static int	ft_draw(v_list *c, int i)
{
	c->spr.spx = c->spr.sx[c->spr.spo[i]] - c->ray.px;
	c->spr.spy = c->spr.sy[c->spr.spo[i]] - c->ray.py;
	c->spr.inv = 1.0 / (c->ray.plx * c->ray.dy - c->ray.dx * c->ray.ply);
	c->spr.tfx = c->spr.inv * (c->ray.dy * c->spr.spx
			- c->ray.dx * c->spr.spy);
	c->spr.tfy = c->spr.inv * (-c->ray.ply * c->spr.spx
			+ c->ray.plx * c->spr.spy);
	c->spr.ssx = (int)((c->res.rx / 2) * (1 + c->spr.tfx / c->spr.tfy));
	c->spr.sph = abs((int)(c->res.ry / c->spr.tfy));
	ft_sprcalc(c);
	return (c->spr.dsx);
}

static void	ft_sprender(v_list *c, int y, int tx, int stripe)
{
	int	d;
	int	ty;

	d = (y) * 256 - c->res.ry * 128 + c->spr.sph * 128;
	ty = ((d * c->tex[4].hgt) / c->spr.sph) / 256;
	if ((int)c->tex[4].adr[ty * c->tex[4].sl / 4 + tx] != -16777216)
		c->mlx.adr[y * c->mlx.sl / 4 + stripe] = c->tex[4].adr[ty
			* c->tex[4].sl / 4 + tx];
}

void	ft_sprisual(v_list *c)
{
	int	y;
	int	tx;
	int	stripe;

	c->uti.i = -1;
	ft_sort(c);
	while (++c->uti.i < c->spr.spc)
	{
		stripe = ft_draw(c, c->uti.i) - 1;
		while (++stripe < c->spr.dex)
		{
			tx = (int)(256 * (stripe - (-c->spr.spw / 2
							+ c->spr.ssx))
					* c->tex[4].wdh / c->spr.spw) / 256;
			if (c->spr.tfy > 0 && stripe >= 0
				&& stripe < c->res.rx
				&& c->spr.tfy < c->spr.zbf[stripe])
			{
				y = c->spr.dsy - 1;
				while (++y < c->spr.dey)
					ft_sprender(c, y, tx, stripe);
			}
		}
	}
}
