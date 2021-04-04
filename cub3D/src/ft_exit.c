/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdesalle <mdesalle@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 10:14:05 by mdesalle          #+#    #+#             */
/*   Updated: 2021/04/04 21:31:53 by mdesalle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

/* frees the whole map */

static void	ft_mfree(t_list *c)
{
	if (c->map.map && c->uti.map == 1 && c->uti.ult != 1)
	{
		while (--c->uti.nbl >= 0)
			free(c->map.map[c->uti.nbl]);
		free(c->map.map);
	}
}

/* frees texture paths */

static void	ft_pfree(t_list *c)
{
	if (c->uti.tex == 1)
	{
		if (c->tex[0].pth)
			free(c->tex[0].pth);
		if (c->tex[1].pth)
			free(c->tex[1].pth);
		if (c->tex[2].pth)
			free(c->tex[2].pth);
		if (c->tex[3].pth)
			free(c->tex[3].pth);
		if (c->tex[4].pth)
			free(c->tex[4].pth);
	}
}

/* frees sprite utilities */

static void	ft_sfree(t_list *c)
{
	if (c->spr.sx)
		free(c->spr.sx);
	if (c->spr.sy)
		free(c->spr.sy);
	if (c->spr.spd)
		free(c->spr.spd);
	if (c->spr.spo)
		free(c->spr.spo);
	if (c->spr.zbf)
		free(c->spr.zbf);
}

/* stops the exit function depending on indicator status */

static void	ft_stop(t_list *c)
{
	if (c->uti.stt == 0)
		exit(0);
}

/* frees everything and destroys the mlx images and windows */

int	ft_exit(t_list *c)
{
	ft_mfree(c);
	ft_pfree(c);
	ft_stop(c);
	ft_sfree(c);
	if (c->mlx.img)
		mlx_destroy_image(c->mlx.mlx, c->mlx.img);
	if (c->mlx.isp)
		mlx_destroy_image(c->mlx.mlx, c->mlx.isp);
	if (c->tex[0].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[0].img);
	if (c->tex[1].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[1].img);
	if (c->tex[2].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[2].img);
	if (c->tex[3].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[3].img);
	if (c->tex[4].img)
		mlx_destroy_image(c->mlx.mlx, c->tex[4].img);
	if (c->mlx.win)
		mlx_destroy_window(c->mlx.mlx, c->mlx.win);
	exit(0);
	return (0);
}
