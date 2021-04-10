/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 09:46:21 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/10 16:34:39 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* computes the path to the texture file */

static int	ft_path(char *line, int type, t_list *c)
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
		c->uti.pth[type] = 1;
		return (0);
	}
	else
		return (ft_error(2, c));
}

/* computes the texture direction being used to render on screen */

static void	ft_texdir(t_list *c)
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

/* assigns the right texture address to the mlx address */

static void	ft_texcol(t_list *c)
{
	int	i;

	ft_texdir(c);
	i = c->ray.ds - 1;
	c->ray.stp = 1.0 * c->tex[0].hgt / c->ray.lh;
	c->ray.tx = (int)(c->ray.wx * (double)c->tex[c->mlx.tdr].wdh);
	if (c->ray.sde == 0 && c->ray.rdx > 0)
		c->ray.tx = c->tex[c->mlx.tdr].wdh - c->ray.tx - 1;
	if (c->ray.sde == 1 && c->ray.rdy < 0)
		c->ray.tx = c->tex[c->mlx.tdr].wdh - c->ray.tx - 1;
	c->ray.txp = (c->ray.ds - c->res.ry / 2 + c->ray.lh / 2) * c->ray.stp;
	while (++i < c->ray.de)
	{
		c->ray.ty = (int)c->ray.txp & (c->tex[c->mlx.tdr].hgt - 1);
		c->ray.txp += c->ray.stp;
		c->mlx.adr[i * c->mlx.sl / 4 + c->ray.rc]
			= c->tex[c->mlx.tdr].adr[c->tex[c->mlx.tdr].sl / 4
			* c->ray.ty + c->ray.tx];
	}
}

/* computes the ceiling, floor and column colors */

void	ft_texplace(t_list *c)
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

/* calls the path computation function with the right arguments */

void	ft_tex(char *line, t_list *c)
{
	int	i;

	i = 0;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] == 'N' && line[i + 1] == 'O')
		ft_path(line, 0, c);
	if (line[i] == 'S' && line[i + 1] == 'O')
		ft_path(line, 3, c);
	if (line[i] == 'W' && line[i + 1] == 'E')
		ft_path(line, 2, c);
	if (line[i] == 'E' && line[i + 1] == 'A')
		ft_path(line, 1, c);
	if (line[i] == 'S' && line[i + 1] == ' ')
		ft_path(line, 4, c);
}
