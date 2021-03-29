/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:46:21 by mdesalle          #+#    #+#             */
/*   Updated: 2021/03/29 09:35:59 by maxdesall        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include <stdio.h>

static int	ft_path(char *line, int type, v_list *c)
{
	int	i;
	int	j;

	i = 0;
	while (line[i] != '\0' && line[i] != '.')
		i++;
	if (line[i] == '.')
	{
		j = ft_strlen(line) - i;
		c->tex[type].pth = ft_substr(line, i, j);
		return (0);
	}
	else
		return (ft_error(2, c));
}

static void	ft_texdir(v_list *c)
{
	if (c->ray.sde == 0 && c->ray.rdx < 0)
		c->mlx.tdr = 0;
	if (c->ray.sde == 0 && c->ray.rdx >= 0)
		c->mlx.tdr = 1;
	if (c->ray.sde == 1 && c->ray.rdy < 0)
		c->mlx.tdr = 2;
	if (c->ray.sde == 1 && c->ray.rdy >= 0)
		c->mlx.tdr = 3;
	if (c->ray.sde == 0)
		c->ray.wx = c->ray.py + c->ray.prp * c->ray.rdy;
	else
		c->ray.wx = c->ray.px + c->ray.prp * c->ray.rdx;
	c->ray.wx -= floor((c->ray.wx));
}

static void	ft_texcol(v_list *c)
{
	int	i;

	i = c->ray.ds - 1;
	ft_texdir(c);
	c->ray.stp = 1.0 * c->tex[0].hgt / c->ray.lh;
	c->ray.tx = (int)(c->ray.wx * (double)c->tex[c->mlx.tdr].wdh);
	if (c->ray.sde == 0 && c->ray.rdx > 0)
		c->ray.tx = c->tex[c->mlx.tdr].wdh - c->ray.tx - 1;
	if (c->ray.sde == 1 && c->ray.rdy < 0)
		c->ray.tx = c->tex[c->mlx.tdr].wdh - c->ray.tx - 1;
	c->ray.txp = (c->ray.ds - c->res.ry / 2 + c->ray.lh / 2) * c->ray.stp;
	while (++i <= c->ray.de)
	{
		c->ray.ty = (int)c->ray.txp & (c->tex[c->mlx.tdr].hgt - 1);
		c->ray.txp += c->ray.stp;
		c->mlx.adr[i * c->mlx.sl / 4 + c->ray.rc] =
			c->tex[c->mlx.tdr].adr[c->ray.ty
			* c->tex[c->mlx.tdr].sl / 4 + c->ray.tx];
	}
}

void	ft_texplace(v_list *c)
{
	int	i;

	i = -1;
	while (++i < c->ray.ds)
		c->mlx.adr[c->mlx.sl / 4 * i + c->ray.rc] = c->fc.c;
	if (i <= c->ray.de)
		ft_texcol(c);
	i = c->ray.de - 1;
	while (++i < c->res.ry)
		c->mlx.adr[c->mlx.sl / 4 * i + c->ray.rc] = c->fc.f;
}

void	ft_tex(char *line, v_list *c)
{
	if (line[0] == 'N' && line[1] == 'O')
		ft_path(line, 0, c);
	if (line[0] == 'S' && line[1] == 'O')
                ft_path(line, 1, c);
	if (line[0] == 'W' && line[1] == 'E')
                ft_path(line, 2, c);
	if (line[0] == 'E' && line[1] == 'A')
                ft_path(line, 3, c);
	if (line[0] == 'S' && line[1] == ' ')
		ft_path(line, 4, c);
}
