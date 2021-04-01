/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/26 08:53:27 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/01 18:08:10 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_sprounter(v_list *c)
{
	int	i;
	int	j;

	j = -1;
	c->spr.spc = 0;
	while (++j < c->uti.nbl)
	{
		i = -1;
		while (++i < c->uti.ll)
		{
			if (c->map.map[j][i] == '2')
				c->spr.spc++;
		}
	}
}

static int	ft_spralloc(v_list *c)
{
	c->spr.sx = malloc(c->spr.spc * sizeof(double));
	c->spr.sy = malloc(c->spr.spc * sizeof(double));
	c->spr.spd = malloc(c->spr.spc * sizeof(double));
	c->spr.spo = malloc(c->spr.spc * sizeof(double));
	c->spr.zbf = malloc(c->res.rx * sizeof(double));
	if (!(c->spr.sx || c->spr.sy || c->spr.spd || c->spr.spo || c->spr.zbf))
		return (ft_error(5, c));
	return (0);
}

void	ft_sort(v_list *c)
{
	int		i;
	int		j;
	double	k;

	j = -1;
	ft_order(c);
	while (++j < c->spr.spc)
	{
		i = -1;
		while (++i < (c->spr.spc - 1))
		{
			if (c->spr.spd[i] < c->spr.spd[i + 1])
			{
				k = c->spr.spd[i];
				c->spr.spd[i] = c->spr.spd[i + 1];
				c->spr.spd[i + 1] = k;
				k = c->spr.spo[i];
				c->spr.spo[i] = c->spr.spo[i + 1];
				c->spr.spo[i + 1] = (int)k;
			}
		}
	}
}

void	ft_sprosition(v_list *c)
{
	int	i;
	int	j;
	int	k;

	j = -1;
	k = 0;
	ft_sprounter(c);
	ft_spralloc(c);
	while (++j < c->uti.nbl)
	{
		i = -1;
		while (++i < c->uti.ll)
		{
			if (c->map.map[j][i] == '2')
			{
				c->spr.sx[k] = (double)i + 0.5;
				c->spr.sy[k] = (double)j + 0.5;
				k++;
			}
		}
	}
}
