/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:21:12 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/01 17:57:01 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_rright(v_list *c)
{
	double	odx;
	double	opx;

	odx = c->ray.dx;
	opx = c->ray.plx;
	c->ray.dx = c->ray.dx * cos(-c->ray.rs) - c->ray.dy * sin(-c->ray.rs);
	c->ray.dy = odx * sin(-c->ray.rs) + c->ray.dy * cos(-c->ray.rs);
	c->ray.plx = c->ray.plx * cos(-c->ray.rs)
		- c->ray.ply * sin(-c->ray.rs);
	c->ray.ply = opx * sin(-c->ray.rs) + c->ray.ply * cos(-c->ray.rs);
}

void	ft_rleft(v_list *c)
{
	double	odx;
	double	opx;

	odx = c->ray.dx;
	opx = c->ray.plx;
	c->ray.dx = c->ray.dx * cos(c->ray.rs) - c->ray.dy * sin(c->ray.rs);
	c->ray.dy = odx * sin(c->ray.rs) + c->ray.dy * cos(c->ray.rs);
	c->ray.plx = c->ray.plx * cos(c->ray.rs)
		- c->ray.ply * sin(c->ray.rs);
	c->ray.ply = opx * sin(c->ray.rs) + c->ray.ply * cos(c->ray.rs);
}

void	ft_horizontal(v_list *c, int option)
{
	if (option == RIGHT_MOVE)
	{
		if (c->map.map[(int)c->ray.py][(int)(c->ray.px + c->ray.dy
			* c->ray.ms)] == '0')
			c->ray.px += c->ray.dy * c->ray.ms;
		if (c->map.map[(int)(c->ray.py
			- c->ray.dx * c->ray.ms)]
				[(int)(c->ray.px)] == '0')
			c->ray.py -= c->ray.dx * c->ray.ms;
	}
	if (option == LEFT_MOVE)
	{
		if (c->map.map[(int)(c->ray.py)][(int)(c->ray.px
			- c->ray.dy * c->ray.ms)] == '0')
			c->ray.px -= c->ray.dy * c->ray.ms;
		if (c->map.map[(int)(c->ray.py + c->ray.dx
			* c->ray.ms)][(int)(c->ray.px)] == '0')
			c->ray.py += c->ray.dx * c->ray.ms;
	}
}

void	ft_vertical(v_list *c, int option)
{
	if (option == FORWARD_MOVE)
	{
		if (c->map.map[(int)(c->ray.py)][(int)(c->ray.px
			+ c->ray.dx * c->ray.ms)] == '0')
			c->ray.px += c->ray.dx * c->ray.ms;
		if (c->map.map[(int)(c->ray.py + c->ray.dy
			* c->ray.ms)][(int)(c->ray.px)] == '0')
			c->ray.py += c->ray.dy * c->ray.ms;
	}
	if (option == BACK_MOVE)
	{
		if (c->map.map[(int)(c->ray.py)][(int)(c->ray.px
			- c->ray.dx * c->ray.ms)] == '0')
			c->ray.px -= c->ray.dx * c->ray.ms;
		if (c->map.map[(int)(c->ray.py - c->ray.dy
			* c->ray.ms)][(int)c->ray.px] == '0')
			c->ray.py -= c->ray.dy * c->ray.ms;
	}
}
