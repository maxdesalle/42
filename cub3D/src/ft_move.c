/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:21:12 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/03 12:17:34 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* rotates the player's perspective to the right */

void	ft_rright(t_list *c)
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

/* rotates the player's perspective to the left */

void	ft_rleft(t_list *c)
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

/* moves the player from left to right */

void	ft_horizontal(t_list *c, int option)
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

/* moves the player backward and forward */

void	ft_vertical(t_list *c, int option)
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
