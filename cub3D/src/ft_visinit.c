/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 08:42:04 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/14 08:46:54 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* initiates all the values for each ray column */

static void	ft_camray(t_list *c)
{
	c->ray.hit = 0;
	c->ray.prp = 0;
	c->ray.cx = (2 * c->ray.rc / (double)c->res.rx) - 1;
	c->ray.rdx = c->ray.dx + (c->ray.plx * c->ray.cx);
	c->ray.rdy = c->ray.dy + (c->ray.ply * c->ray.cx);
	c->ray.mx = (int)c->ray.px;
	c->ray.my = (int)c->ray.py;
	c->ray.ms = 0.08;
	c->ray.rs = 0.04;
}

/* calculates the sidedistance */

static void	ft_sdcalc(t_list *c)
{
	if (c->ray.rdx < 0)
	{
		c->ray.sx = -1;
		c->ray.sdx = (c->ray.px - (double)c->ray.mx) * c->ray.ddx;
	}
	else
	{
		c->ray.sx = 1;
		c->ray.sdx = ((double)c->ray.mx + 1.0 - c->ray.px) * c->ray.ddx;
	}
	if (c->ray.rdy < 0)
	{
		c->ray.sy = -1;
		c->ray.sdy = (c->ray.py - (double)c->ray.my) * c->ray.ddy;
	}
	else
	{
		c->ray.sy = 1;
		c->ray.sdy = ((double)c->ray.my + 1.0 - c->ray.py) * c->ray.ddy;
	}
}

/* checks if a wall was hit */

static void	ft_hit(t_list *c)
{
	while (c->ray.hit == 0)
	{
		if (c->ray.sdx < c->ray.sdy)
		{
			c->ray.sdx += c->ray.ddx;
			c->ray.mx += c->ray.sx;
			c->ray.sde = 0;
		}
		else
		{
			c->ray.sdy += c->ray.ddy;
			c->ray.my += c->ray.sy;
			c->ray.sde = 1;
		}
		if (c->map.map[c->ray.my][c->ray.mx] == '1')
			c->ray.hit = 1;
	}
}

/* calls the right functions */

void	ft_visinit(t_list *c)
{
	ft_camray(c);
	ft_delta(c);
	ft_sdcalc(c);
	ft_hit(c);
	ft_height(c);
}

/* initiates the orientation values (dirX/Y and planeX/Y) */

void	ft_orinit(t_list *c)
{
	if (c->uti.dep != 1)
		ft_error(4, c);
	if (c->map.ori == 3)
	{
		c->ray.dx = -1;
		c->ray.ply = 0.66;
	}
	if (c->map.ori == 4)
	{
		c->ray.dx = 1;
		c->ray.ply = -0.66;
	}
	if (c->map.ori == 5)
	{
		c->ray.dy = 1;
		c->ray.plx = 0.66;
	}
	if (c->map.ori == 6)
	{
		c->ray.dy = -1;
		c->ray.plx = -0.66;
	}
}
